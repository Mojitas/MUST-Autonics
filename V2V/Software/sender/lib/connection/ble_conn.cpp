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
  eventHandler = new CretEvents(_ble);
  _builder = new DataBuilder();
}

Advertiser::~Advertiser() 
{
  if (_ble.hasInitialized())
    _ble.shutdown();
}

void Advertiser::run()
{
  _gap.setEventHandler(eventHandler);
  _ble.init(this, &Advertiser::on_ble_init_complete);
  _event_queue.dispatch_forever();
}

void Advertiser::on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context)
{
  BLE &ble = context->ble.Instance();
  Gap &gap = ble.gap();
  ble_error_t error = context->error;

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

  _event_queue.call(this, &Advertiser::advertise);
}

void Advertiser::advertise()
{
  if (_ble.hasInitialized())
  {
    ble_error_t error;
    ble::AdvertisingParameters advparams(
        ble::advertising_type_t::CONNECTABLE_NON_SCANNABLE_UNDIRECTED,
        ble::adv_interval_t(ble::millisecond_t(100))
    );

    advparams.setUseLegacyPDU(false);
    
    error = _ble.gap().createAdvertisingSet(&adv_handle, advparams);
    if (error)
    {
      printf("%s: createAdvertisingSet() failed!\r\n", _ble.errorToString(error));
      return;
    }

    ble::AdvertisingDataBuilder data_builder = _builder->initialize(_ble);
    error = _ble.gap().setAdvertisingPayload(adv_handle, data_builder.getAdvertisingData());
    if (error)
    {
      printf("%s: setAdvertisingPayload() failed!\r\n", _ble.errorToString(error));
      return;
    }

    ble::millisecond_t random_duration_ms((2 + rand() % 5) * 1000);
    ble::adv_duration_t random_duration(random_duration_ms);

    error = _ble.gap().startAdvertising(adv_handle, random_duration);
    if (error)
    {
      printf("%s: startAdvertising() failed!\r\n", _ble.errorToString(error));
    }

    printf("BLE started advertising for %ldms\r\n", random_duration_ms.valueInMs());
  }
}
