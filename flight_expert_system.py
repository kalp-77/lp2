# Define the Knowledge Base

flights = {
    "F1": {
        "origin": "City A",
        "destination": "City B",
        "departure_time": "09:00",
        "arrival_time": "11:00",
        "available_seats": 50,
        "cargo_capacity": 1000
    },
    "F2": {
        "origin": "City B",
        "destination": "City C",
        "departure_time": "12:00",
        "arrival_time": "14:00",
        "available_seats": 30,
        "cargo_capacity": 800
    },
    # Add more flights as needed
}

# Define the Inference Engine

def find_available_flights(origin, destination):
    available_flights = []
    for flight_id, flight_details in flights.items():
        if flight_details["origin"] == origin and flight_details["destination"] == destination:
            available_flights.append(flight_id)
    return available_flights

def check_seat_availability(flight_id):
    if flight_id in flights:
        return flights[flight_id]["available_seats"] > 0
    return False

def check_cargo_capacity(flight_id, cargo_weight):
    if flight_id in flights:
        return cargo_weight <= flights[flight_id]["cargo_capacity"]
    return False

# User Interface

def main():
    origin = input("Enter the origin city: ")
    destination = input("Enter the destination city: ")
    cargo_weight = int(input("Enter the weight of the cargo (in kg): "))

    available_flights = find_available_flights(origin, destination)

    if not available_flights:
        print("No available flights for the given route.")
    else:
        for flight_id in available_flights:
            if check_seat_availability(flight_id) and check_cargo_capacity(flight_id, cargo_weight):
                print("Flight {} is available.".format(flight_id))
                # Add additional actions or recommendations based on your requirements

if __name__ == "__main__":
    main()
