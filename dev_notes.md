# TODO

- Get defs on startup
  - dao -> Get_defs
  - dam -> Get_defs
  - Struct in the defs file
  - create a pointer to this struct in main
  - pass to each generator

- Fix handling of config - child classes should get their own copy of their own config

- Modify instantiation of config, probably don't need it defined outside of main. Model it after data access manager
- rethink shared pointers everywhere, specifically how to handle generated history
- figure out what functions to make const

# Notes

