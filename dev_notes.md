# TODO


# Notes

template constructor to allowing passing different params for different transport types
  - structs to manage the params for each type
  - enum for each type of data 
overloaded constructors for each type of transport, so when DAM is instantiated, it's instantiated with that type of config. So DAM

in gstransport:
- one ctor for each type of config struct
- gstransport manages m_pxport, which is a byte interface
- m_pxport is instantiated with the config for one of byte_interface's implementing classe


instantiate the DAM in main, pass it to each generator
DAM instantiate with an enum for data access type





Each generator will have an instance of the DAM class
- The will have templated constructors allowing different config for the DAM, depending on the data access type

So when a generator calls eg 'save_entity', it calls a matching function in the DAM

so are all the functions in the DAM templated for the data acces object type, in turn calling the corresponding function in the dao?
We use three different constructors for DAM, corresponding to each type, so that when we instantiate the DAM with a set of config.

so we call DAM.save_entity from a generator, it will call DAO.save_entity, and then we put the specifics in the DAO.save_entity functionl



we may want to change inheritance in the data access layer, based on how the data access functions will be called
