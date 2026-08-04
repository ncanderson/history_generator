## Application Architecture

### Event_visitor

The `Event_visitor` class provides a means for specific event/entity pairings to initialize necessary attributes. By calling `Accept_event` on an entity when it receives an event, that entity instance can perform required steps to work with that event.

