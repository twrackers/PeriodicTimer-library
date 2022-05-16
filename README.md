# PeriodicTimer #

The `PeriodicTimer` class is derived from the `StateMachine` class ([https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)).  A *PeriodicTimer* object mimics an alarm which is set to go off at a regular interval settable when the alarm is "armed" (started).  When the alarm goes off, its alarmed state will persist until it is interrogated, which will "reset" the alarm.  This cycle will repeat until the timer object is "disarmed" (stopped).

## Examples ##

Example sources are currently being prepared.

## Dependencies ##

The `PeriodicTimer` library itself depends on the `StateMachine` library.

## Installation ##

Instructions for installing the `PeriodicTimer` library will be found in file `INSTALL.md`, currently being prepared.
