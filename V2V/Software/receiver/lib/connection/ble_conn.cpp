#include "ble_conn.h"

/*!
 * \file ble_conn.cpp
 * \brief Implements functions from ble_conn.h
 */

void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context)
{
  event_queue.call(callback(&(context->ble),  &BLE::processEvents));
}

Advertiser::Advertiser(BLE &ble) : _ble(ble), _gap(ble.gap()), _event_queue(EVENTS_QUEUE_SIZE)
{
  _builder = new DataBuilder();
}

Advertiser::~Advertiser() 
{
  if (_ble.hasInitialized())
    _ble.shutdown();
}

void Advertiser::run()
{
  _ble.init(this, &Advertiser::on_ble_init_complete);
  _event_queue.dispatch_forever();
}

void Advertiser::on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context)
{
  BLE &ble = context->ble.Instance();
  Gap &gap = ble.gap();
  error = context->error;

  if (error)
  {
    printf("%s: Ble initialization failed!\r\n", ble.errorToString(error));
    return;
  }

  if (gap.isFeatureSupported(ble::controller_supported_features_t::LE_CODED_PHY))
  {
    ble::phy_set_t sendingPhys(ble::phy_t::LE_CODED);
    error = gap.setPreferredPhys(&sendingPhys, &sendingPhys);
    if (error) {
      printf("%s: setPreferredPhys() failed\r\n", ble.errorToString(error));
    }
  }

  _event_queue.call(this, &Advertiser::device_scan);
}

void Advertiser::device_scan()
{
  ble::ScanParameters scan_params;
  scan_params.setOwnAddressType(ble::own_address_type_t::RANDOM);
  error = _gap.setScanParameters(scan_params);
  if (error) 
  {
    printf("%s: setScanParameters failed!\r\n", BLE::errorToString(error));
    return;
  }

  error = _gap.startScan(ble::scan_duration_t(500));
  if (error)
  {
    printf("%s: startScan faied!\r\n", BLE::errorToString(error));
    return;
  }

  printf("Scanning started!\r\n");
}

