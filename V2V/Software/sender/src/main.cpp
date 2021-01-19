#include "user_headers.h"
#include "data_builder.h"
#include "battery.h"

static events::EventQueue event_queue(32 * EVENTS_EVENT_SIZE);

void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context)
{
  event_queue.call(callback(&(context->ble),  &BLE::processEvents));
}

void on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context)
{
  BLE &ble = context->ble;
  ble_error_t error = context->error;

  if (error)
  {

  }
}

int main(void)
{
  // Instantiate the ble device
  BLE &ble = BLE::Instance();
  
  // Setup an event handler
  ble.onEventsToProcess(schedule_ble_processing);

  // Initialize the BLE device
  ble.init(on_ble_init_complete);

  event_queue.dispatch_forever();
  return 0;
}
