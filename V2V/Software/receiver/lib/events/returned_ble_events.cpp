#include "returned_ble_events.h"


/*!
 * \file returned_ble_events.cpp
 * \include returned_ble_events.h
 * \brief Implements function headers found in the included header file.
 */
CretEvents::CretEvents(BLE &ble) : _advertiser(ble)
{
}

CretEvents::~CretEvents()
{
  _advertiser.~Advertiser();
}

void CretEvents::run()
{
  // Set the event handler to this class
  _advertiser._gap.setEventHandler(this);

  // Call the super function with the same name that runs the BLE module
  _advertiser.run();
}

void CretEvents::onAdvertisingReport(const ble::AdvertisingReportEvent &event)
{
  if (is_connecting)
    return;

  // Print the mac address of the peer
  ble::address_t peer = event.getPeerAddress();
  ble::peer_address_type_t type = event.getPeerAddressType();
  bool is_connectable = event.getType().connectable();
  printf("Peer address: ");
  print_mac_address(peer);

  // Print the RSSI value of the other device
  ble::rssi_t value = event.getRssi();
  printf("RSSI: %d dBm", value);

  // Look only at devices nearby
  if (value < -60)
  {
    printf("Device too far away!\r\n");
    return;
  }

  ble::AdvertisingDataParser parser(event.getPayload());
  bool is_peer_device = false;
  while (parser.hasNext())
  {
    ble::AdvertisingDataParser::element_t field = parser.next();
    if (field.type == ble::adv_data_type_t::SHORTENED_LOCAL_NAME ||
        field.type == ble::adv_data_type_t::COMPLETE_LOCAL_NAME)
    {
      const char *peer_name = reinterpret_cast<const char *>(field.value.data());
      if (peer_name == nullptr)
        printf("Reinterpreting unsigned char as char failed!\r\n");

      if (strncmp(NAME_SENDER, peer_name, strlen(peer_name)) == 0)
        is_peer_device = true;
    }
  }

  if (is_connectable && is_peer_device && !_advertiser.is_connected)
  {
    _advertiser.error = _advertiser._gap.connect(type, peer, ble::ConnectionParameters());
    if (_advertiser.error)
    {
      printf("%s: connect() failed!\r\n", BLE::errorToString(_advertiser.error));
    }
  }
}

void CretEvents::onConnectionComplete(const ble::ConnectionCompleteEvent &event)
{
  _advertiser.error = event.getStatus();
  if (_advertiser.error)
  {
    printf("%s: Connection failed!\r\n", BLE::errorToString(_advertiser.error));
    return;
  }

  _advertiser._handle = event.getConnectionHandle();
  ble::phy_set_t phySet(false, false, true);
  ble::coded_symbol_per_bit_t bitSymbol(ble::coded_symbol_per_bit_t::S8);
  _advertiser.error = _advertiser._gap.setPhy(_advertiser._handle, &phySet, &phySet, bitSymbol);
  if (_advertiser.error)
  {
    printf("%s: Setting 8 symbols per bit did not work!\r\n", BLE::errorToString(_advertiser.error));
  }
}

void CretEvents::onPeriodicAdvertisingReport(const ble::PeriodicAdvertisingReportEvent &event)
{
  ble::rssi_t received = event.getRssi();
  if (received < -60) {
    printf("Signal is bad.\r\n");
  }

  if (event.getDataStatus() == ble::advertising_data_status_t::INCOMPLETE_DATA_TRUNCATED)
  {
    printf("No more data is coming, package is most likely truncated/corrupt.\r\n");
    return;
  }
  else if (event.getDataStatus() == ble::advertising_data_status_t::INCOMPLETE_MORE_DATA)
  {
    printf("Waiting for more data!\r\n");
    return;
  }
  else
  {
    ble::AdvertisingDataParser advParser(event.getPayload());
    while (advParser.hasNext())
    {
      /**
       * Parse data received on periodic advertisement here
       */
    }
  }
}
