cmake_minimum_required(VERSION 3.30)
project(03_jf_flight_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(03_jf_flight_system main.cpp
        Person.cpp
        Person.h
        Pilot.cpp
        Pilot.h
        Passenger.cpp
        Passenger.h
        Aircraft.cpp
        Aircraft.h
        Airliner.cpp
        Airliner.h
        Cargo.cpp
        Cargo.h
        Flight.cpp
        Flight.h
        Airport.cpp
        Airport.h
        CargoFlight.cpp
        CargoFlight.h
        PassengerFlight.cpp
        PassengerFlight.h)
