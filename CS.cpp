#include <iostream>
#include <string>
#include <fstream>
#include <vector> // Added for predefined services
using namespace std;
const int MAX_SIZE = 100;
const double COST_PER_GUEST = 25.0;

// Forward declaration for Event
class Event;

// Base class for polymorphism
class Person {
public:
    virtual void getInput() = 0;
    virtual void display() const = 0;
    virtual ~Person() {}
};

class Staff : public Person {
private:
    string staffID, name, role;
public:
    // Constructors
    Staff() : staffID(""), name(""), role("") {}
    Staff(const Staff& other) : staffID(other.staffID), name(other.name), role(other.role) {}
    
    // Destructor
    ~Staff() {}
    
    // Getters
    string getStaffID() const { return staffID; }
    string getName() const { return name; }
    string getRole() const { return role; }
    
    // Setters
    void setStaffID(const string& id) { staffID = id; }
    void setName(const string& n) { name = n; }
    void setRole(const string& r) { role = r; }
    
    void getInput() override {
        cout << "Enter Staff ID: "; cin >> staffID;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Role: "; cin >> role;
    }
    void display() const override {
        cout << "Staff ID: " << staffID << "\nName: " << name << "\nRole: " << role << endl;
    }
};

class Invitation {
private:
    string invitationID, guestName, status;
public:
    // Constructors
    Invitation() : invitationID(""), guestName(""), status("") {}
    Invitation(const Invitation& other) : invitationID(other.invitationID), guestName(other.guestName), status(other.status) {}
    
    // Destructor
    ~Invitation() {}
    
    // Getters
    string getInvitationID() const { return invitationID; }
    string getGuestName() const { return guestName; }
    string getStatus() const { return status; }
    
    // Setters
    void setInvitationID(const string& id) { invitationID = id; }
    void setGuestName(const string& guest) { guestName = guest; }
    void setStatus(const string& s) { status = s; }
    
    void getInput() {
        cout << "Enter Invitation ID: "; cin >> invitationID;
        cout << "Enter Guest Name: "; cin >> guestName;
        cout << "Enter Status: "; cin >> status;
    }
    void display() const {
        cout << "Invitation ID: " << invitationID << "\nGuest: " << guestName << "\nStatus: " << status << endl;
    }
};

class Venue {
private:
    string venueID, location;
    int capacity;
    double rentalCost;
public:
    // Constructors
    Venue() : venueID(""), location(""), capacity(0), rentalCost(0) {}
    Venue(const Venue& other) : venueID(other.venueID), location(other.location), 
                                capacity(other.capacity), rentalCost(other.rentalCost) {}
    
    // Destructor
    ~Venue() {}
    
    // Getters
    string getVenueID() const { return venueID; }
    string getLocation() const { return location; }
    int getCapacity() const { return capacity; }
    double getRentalCost() const { return rentalCost; }
    
    // Setters
    void setVenueID(const string& id) { venueID = id; }
    void setLocation(const string& loc) { location = loc; }
    void setCapacity(int cap) { capacity = cap; }
    void setRentalCost(double cost) { rentalCost = cost; }
    
    void getInput() {
        cout << "Enter Venue ID: "; cin >> venueID;
        cout << "Enter Location: "; cin >> location;
        cout << "Enter Capacity: "; cin >> capacity;
        cout << "Enter Rental Cost: $"; cin >> rentalCost;
    }
    void display() const {
        cout << "Venue ID: " << venueID << "\nLocation: " << location 
             << "\nCapacity: " << capacity << "\nRental Cost: $" << rentalCost << endl;
    }
};

class Host : public Person {
private:
    string hostID, name, contact;
public:
    // Constructors
    Host() : hostID(""), name(""), contact("") {}
    Host(const Host& other) : hostID(other.hostID), name(other.name), contact(other.contact) {}
    
    // Destructor
    ~Host() {}
    
    // Getters
    string getHostID() const { return hostID; }
    string getName() const { return name; }
    string getContact() const { return contact; }
    
    // Setters
    void setHostID(const string& id) { hostID = id; }
    void setName(const string& n) { name = n; }
    void setContact(const string& c) { contact = c; }
    
    void getInput() override {
        cout << "Enter Host ID: "; cin >> hostID;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Contact: "; cin >> contact;
    }
    void display() const override {
        cout << "Host ID: " << hostID << "\nName: " << name << "\nContact: " << contact << endl;
    }
};

class Service {
private:
    string serviceID, type;
    double cost;
public:
    // Constructors
    Service() : serviceID(""), type(""), cost(0) {}
    Service(string id, string t, double c) : serviceID(id), type(t), cost(c) {} // Added parameterized constructor
    Service(const Service& other) : serviceID(other.serviceID), type(other.type), cost(other.cost) {}
    
    // Destructor
    ~Service() {}
    
    // Getters
    string getServiceID() const { return serviceID; }
    string getType() const { return type; }
    double getCost() const { return cost; }
    
    // Setters
    void setServiceID(const string& id) { serviceID = id; }
    void setType(const string& t) { type = t; }
    void setCost(double c) { cost = c; }
    
    void getInput() {
        cout << "Enter Service ID: "; cin >> serviceID;
        cout << "Enter Type: "; cin >> type;
        cout << "Enter Cost: $"; cin >> cost;
    }
    void display() const {
        cout << "Service ID: " << serviceID << "\nType: " << type << "\nCost: $" << cost << endl;
    }
};

class Bill {
private:
    string billID;
    double totalAmount;
    Event* associatedEvent;
public:
    // Constructors
    Bill() : billID(""), totalAmount(0), associatedEvent(nullptr) {}
    Bill(const Bill& other) : billID(other.billID), totalAmount(other.totalAmount), associatedEvent(nullptr) {}
    
    // Destructor
    ~Bill() {}
    
    // Getters
    string getBillID() const { return billID; }
    double getTotalAmount() const { return totalAmount; }
    
    // Setters
    void setBillID(const string& id) { billID = id; }
    void setTotalAmount(double amount) { totalAmount = amount; }
    
    void generateBill(Event* e);
    void display() const;
};

class Event {
private:
    string eventID, name, date;
    Venue* venue;
    Host* host;
    Service* service;
    Invitation* invitation;
    Bill* bill;
    int numGuests;
public:
    // Constructors
    Event() : eventID(""), name(""), date(""), venue(nullptr), host(nullptr), 
              service(nullptr), invitation(nullptr), bill(nullptr), numGuests(0) {}
    Event(const Event& other);
    
    // Destructor
    ~Event() {
        delete venue;
        delete host;
        delete service;
        delete invitation;
        delete bill;
    }
    
    // Getters
    string getEventID() const { return eventID; }
    string getName() const { return name; }
    string getDate() const { return date; }
    Venue* getVenue() const { return venue; }
    Host* getHost() const { return host; }
    Service* getService() const { return service; }
    Invitation* getInvitation() const { return invitation; }
    Bill* getBill() const { return bill; }
    int getNumGuests() const { return numGuests; }
    
    // Setters
    void setEventID(const string& id) { eventID = id; }
    void setName(const string& n) { name = n; }
    void setDate(const string& d) { date = d; }
    void setNumGuests(int n) { numGuests = n; }
   
    Event& operator=(const Event& other) {
        if (this != &other) {
            delete venue;
            delete host;
            delete service;
            delete invitation;
            delete bill;

            eventID = other.eventID;
            name = other.name;
            date = other.date;
            numGuests = other.numGuests;
            venue = new Venue(*other.venue);
            host = new Host(*other.host);
            service = new Service(*other.service);
            invitation = new Invitation(*other.invitation);
            bill = other.bill ? new Bill(*other.bill) : nullptr;
        }
        return *this;
    }
    
    void getInput(Venue* v, Host* h, Service* s, Invitation* i) {
        cout << "Enter Event ID: "; cin >> eventID;
        cout << "Enter Event Name: "; cin >> name;
        cout << "Enter Date: "; cin >> date;
        venue = new Venue(*v);
        host = new Host(*h);
        service = new Service(*s);
        invitation = new Invitation(*i);
    }
    Bill* createBill() {
        bill = new Bill();
        bill->generateBill(this);
        return bill;
    }
    void display() const;
};
void Bill::generateBill(Event* e) {
    associatedEvent = e;
    cout << "Enter Bill ID: "; cin >> billID;
    totalAmount = e->getVenue()->getRentalCost() + e->getService()->getCost() + 
                 (e->getNumGuests() * COST_PER_GUEST);
}

void Bill::display() const {
    cout << "\nBill ID: " << billID << "\nTotal Amount: $" << totalAmount << endl;
    if(associatedEvent) {
        cout << "Associated Event:\n";
        associatedEvent->display();
    }
}

// Event copy constructor
Event::Event(const Event& other) : 
    eventID(other.eventID), name(other.name), date(other.date),
    numGuests(other.numGuests),
    venue(new Venue(*other.venue)),
    host(new Host(*other.host)),
    service(new Service(*other.service)),
    invitation(new Invitation(*other.invitation)),
    bill(other.bill ? new Bill(*other.bill) : nullptr) {}

void Event::display() const {
    cout << "\nEvent ID: " << eventID << "\nName: " << name << "\nDate: " << date 
         << "\nNumber of Guests: " << numGuests << endl;
    cout << "\nVenue Details:\n"; venue->display();
    cout << "\nHost Details:\n"; host->display();
    cout << "\nService Details:\n"; service->display();
    cout << "\nInvitation Details:\n"; invitation->display();
    if(bill) {
        cout << "\nBill Details:\n"; 
        bill->display();
    }
}

// ================= Collection Classes (Updated with CRUD and file handling) =================
class StaffCollection {
    Staff staffs[MAX_SIZE];
    int count;
public:
    StaffCollection() : count(0) {}
    
    void addStaff() {
        if(count < MAX_SIZE) {
            staffs[count].getInput();
            count++;
        } else cout << "Max staff reached!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            staffs[i].display();
            cout << endl;
        }
    }
    
    void updateStaff() {
        if(count == 0) {
            cout << "No staff to update!\n";
            return;
        }
        string id;
        cout << "Enter Staff ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(staffs[i].getStaffID() == id) {
                staffs[i].getInput();
                cout << "Staff updated!\n";
                return;
            }
        }
        cout << "Staff ID not found!\n";
    }
    
    void deleteStaff() {
        if(count == 0) {
            cout << "No staff to delete!\n";
            return;
        }
        string id;
        cout << "Enter Staff ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(staffs[i].getStaffID() == id) {
                for(int j=i; j<count-1; j++) staffs[j] = staffs[j+1];
                count--;
                cout << "Staff deleted!\n";
                return;
            }
        }
        cout << "Staff ID not found!\n";
    }

    // File handling methods
    void saveToFile(ofstream& outFile) {
        outFile << count << endl;
        for(int i=0; i<count; i++) {
            outFile << staffs[i].getStaffID() << endl;
            outFile << staffs[i].getName() << endl;
            outFile << staffs[i].getRole() << endl;
        }
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> count;
        inFile.ignore();
        for(int i=0; i<count; i++) {
            string id, name, role;
            getline(inFile, id);
            getline(inFile, name);
            getline(inFile, role);
            staffs[i].setStaffID(id);
            staffs[i].setName(name);
            staffs[i].setRole(role);
        }
    }
};

class InvitationCollection { 
    Invitation invitations[MAX_SIZE];
    int count;
public:
    InvitationCollection() : count(0) {}
    
    void addInvitation() {
        if(count < MAX_SIZE) {
            invitations[count].getInput();
            count++;
        } else cout << "Max invitations reached!\n";
    }
    
    void generateInvitations(int numGuests) {
        if(count + numGuests >= MAX_SIZE) {
            cout << "Cannot generate invitations - exceeds maximum capacity!\n";
            return;
        }
        
        for(int i = 0; i < numGuests; i++) {
            cout << "Enter details for Guest #" << i+1 << ":\n";
            invitations[count].getInput();
            count++;
        }
        cout << numGuests << " invitations generated successfully!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            invitations[i].display();
            cout << endl;
        }
    }
    
    Invitation* getLast() { return count > 0 ? &invitations[count-1] : NULL; }
    
    void updateInvitation() {
        if(count == 0) {
            cout << "No invitations to update!\n";
            return;
        }
        string id;
        cout << "Enter Invitation ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(invitations[i].getInvitationID() == id) {
                invitations[i].getInput();
                cout << "Invitation updated!\n";
                return;
            }
        }
        cout << "Invitation ID not found!\n";
    }
    
    void deleteInvitation() {
        if(count == 0) {
            cout << "No invitations to delete!\n";
            return;
        }
        string id;
        cout << "Enter Invitation ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(invitations[i].getInvitationID() == id) {
                for(int j=i; j<count-1; j++) invitations[j] = invitations[j+1];
                count--;
                cout << "Invitation deleted!\n";
                return;
            }
        }
        cout << "Invitation ID not found!\n";
    }

    // File handling methods
    void saveToFile(ofstream& outFile) {
        outFile << count << endl;
        for(int i=0; i<count; i++) {
            outFile << invitations[i].getInvitationID() << endl;
            outFile << invitations[i].getGuestName() << endl;
            outFile << invitations[i].getStatus() << endl;
        }
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> count;
        inFile.ignore();
        for(int i=0; i<count; i++) {
            string id, guest, status;
            getline(inFile, id);
            getline(inFile, guest);
            getline(inFile, status);
            invitations[i].setInvitationID(id);
            invitations[i].setGuestName(guest);
            invitations[i].setStatus(status);
        }
    }
};

class VenueCollection { 
    Venue venues[MAX_SIZE];
    int count;
public:
    VenueCollection() : count(0) {}
    
    void addVenue() {
        if(count < MAX_SIZE) {
            venues[count].getInput();
            count++;
        } else cout << "Max venues reached!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            venues[i].display();
            cout << endl;
        }
    }
    
    Venue* getLast() { return count > 0 ? &venues[count-1] : NULL; }
    
    void updateVenue() {
        if(count == 0) {
            cout << "No venues to update!\n";
            return;
        }
        string id;
        cout << "Enter Venue ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(venues[i].getVenueID() == id) {
                venues[i].getInput();
                cout << "Venue updated!\n";
                return;
            }
        }
        cout << "Venue ID not found!\n";
    }
    
    void deleteVenue() {
        if(count == 0) {
            cout << "No venues to delete!\n";
            return;
        }
        string id;
        cout << "Enter Venue ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(venues[i].getVenueID() == id) {
                for(int j=i; j<count-1; j++) venues[j] = venues[j+1];
                count--;
                cout << "Venue deleted!\n";
                return;
            }
        }
        cout << "Venue ID not found!\n";
    }

    // File handling methods
    void saveToFile(ofstream& outFile) {
        outFile << count << endl;
        for(int i=0; i<count; i++) {
            outFile << venues[i].getVenueID() << endl;
            outFile << venues[i].getLocation() << endl;
            outFile << venues[i].getCapacity() << endl;
            outFile << venues[i].getRentalCost() << endl;
        }
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> count;
        inFile.ignore();
        for(int i=0; i<count; i++) {
            string id, location;
            int capacity;
            double cost;
            getline(inFile, id);
            getline(inFile, location);
            inFile >> capacity;
            inFile >> cost;
            inFile.ignore();
            venues[i].setVenueID(id);
            venues[i].setLocation(location);
            venues[i].setCapacity(capacity);
            venues[i].setRentalCost(cost);
        }
    }
};

class HostCollection { 
    Host hosts[MAX_SIZE];
    int count;
public:
    HostCollection() : count(0) {}
    
    void addHost() {
        if(count < MAX_SIZE) {
            hosts[count].getInput();
            count++;
        } else cout << "Max hosts reached!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            hosts[i].display();
            cout << endl;
        }
    }
    
    Host* getLast() { return count > 0 ? &hosts[count-1] : NULL; }
    int getCount() { return count; }
    
    void updateHost() {
        if(count == 0) {
            cout << "No hosts to update!\n";
            return;
        }
        string id;
        cout << "Enter Host ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(hosts[i].getHostID() == id) {
                hosts[i].getInput();
                cout << "Host updated!\n";
                return;
            }
        }
        cout << "Host ID not found!\n";
    }
    
    void deleteHost() {
        if(count == 0) {
            cout << "No hosts to delete!\n";
            return;
        }
        string id;
        cout << "Enter Host ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(hosts[i].getHostID() == id) {
                for(int j=i; j<count-1; j++) hosts[j] = hosts[j+1];
                count--;
                cout << "Host deleted!\n";
                return;
            }
        }
        cout << "Host ID not found!\n";
    }

    // File handling methods
    void saveToFile(ofstream& outFile) {
        outFile << count << endl;
        for(int i=0; i<count; i++) {
            outFile << hosts[i].getHostID() << endl;
            outFile << hosts[i].getName() << endl;
            outFile << hosts[i].getContact() << endl;
        }
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> count;
        inFile.ignore();
        for(int i=0; i<count; i++) {
            string id, name, contact;
            getline(inFile, id);
            getline(inFile, name);
            getline(inFile, contact);
            hosts[i].setHostID(id);
            hosts[i].setName(name);
            hosts[i].setContact(contact);
        }
    }
};

class ServiceCollection { 
    Service services[MAX_SIZE];
    int count;
    vector<Service> predefinedServices; // Store predefined services
public:
    ServiceCollection() : count(0) {
        // Initialize predefined services
        predefinedServices.push_back(Service("S001", "Catering", 500.0));
        predefinedServices.push_back(Service("S002", "Photography", 300.0));
        predefinedServices.push_back(Service("S003", "Decorations", 400.0));
        predefinedServices.push_back(Service("S004", "Sound System", 350.0));
        predefinedServices.push_back(Service("S005", "Security", 250.0));
    }
    
    void addService() {
        if(count < MAX_SIZE) {
            services[count].getInput();
            count++;
        } else cout << "Max services reached!\n";
    }
    
    void addPredefinedService(int index) {
        if (count < MAX_SIZE && index >= 0 && index < predefinedServices.size()) {
            services[count] = predefinedServices[index];
            count++;
            cout << "Added predefined service: " << predefinedServices[index].getType() 
                 << " ($" << predefinedServices[index].getCost() << ")\n";
        } else {
            cout << "Invalid service selection or max services reached!\n";
        }
    }
    
    void displayPredefinedServices() {
        cout << "\nPredefined Services:\n";
        for (int i = 0; i < predefinedServices.size(); i++) {
            cout << i+1 << ". ";
            predefinedServices[i].display();
        }
    }
    
    void displayAll() {
        cout << "\nAll Available Services:\n";
        for(int i=0; i<count; i++) {
            services[i].display();
            cout << endl;
        }
    }
    
    Service* getLast() { return count > 0 ? &services[count-1] : NULL; }
    
    void updateService() {
        if(count == 0) {
            cout << "No services to update!\n";
            return;
        }
        string id;
        cout << "Enter Service ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(services[i].getServiceID() == id) {
                services[i].getInput();
                cout << "Service updated!\n";
                return;
            }
        }
        cout << "Service ID not found!\n";
    }
    
    void deleteService() {
        if(count == 0) {
            cout << "No services to delete!\n";
            return;
        }
        string id;
        cout << "Enter Service ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(services[i].getServiceID() == id) {
                for(int j=i; j<count-1; j++) services[j] = services[j+1];
                count--;
                cout << "Service deleted!\n";
                return;
            }
        }
        cout << "Service ID not found!\n";
    }

    // File handling methods
    void saveToFile(ofstream& outFile) {
        outFile << count << endl;
        for(int i=0; i<count; i++) {
            outFile << services[i].getServiceID() << endl;
            outFile << services[i].getType() << endl;
            outFile << services[i].getCost() << endl;
        }
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> count;
        inFile.ignore();
        for(int i=0; i<count; i++) {
            string id, type;
            double cost;
            getline(inFile, id);
            getline(inFile, type);
            inFile >> cost;
            inFile.ignore();
            services[i].setServiceID(id);
            services[i].setType(type);
            services[i].setCost(cost);
        }
    }
};
class EventCollection { 
    Event events[MAX_SIZE];
    int count;
public:
    EventCollection() : count(0) {}
    
    void addEvent(Event e) {
        if(count < MAX_SIZE) {
            events[count] = e;
            count++;
        } else cout << "Max events reached!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            events[i].display();
            cout << endl;
        }
    }
    
    Event* getLast() { return count > 0 ? &events[count-1] : NULL; }
    
    int getCount() { return count; }
   
    void updateEvent() {
        if(count == 0) {
            cout << "No events to update!\n";
            return;
        }
        string id;
        cout << "Enter Event ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(events[i].getEventID() == id) {
                events[i].display();
                cout << "Re-enter event details:\n";
                cout << "Update not fully implemented (requires dependencies)\n";
                return;
            }
        }
        cout << "Event ID not found!\n";
    }
    
    void deleteEvent() {
        if(count == 0) {
            cout << "No events to delete!\n";
            return;
        }
        string id;
        cout << "Enter Event ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(events[i].getEventID() == id) {
                for(int j=i; j<count-1; j++) events[j] = events[j+1];
                count--;
                cout << "Event deleted!\n";
                return;
            }
        }
        cout << "Event ID not found!\n";
    }
};

class BillCollection {
    Bill bills[MAX_SIZE];
    int count;
public:
    BillCollection() : count(0) {}
    
    void addBill(Bill b) {
        if(count < MAX_SIZE) {
            bills[count] = b;
            count++;
        } else cout << "Max bills reached!\n";
    }
    
    void displayAll() {
        for(int i=0; i<count; i++) {
            bills[i].display();
            cout << endl;
        }
    }
    
    void updateBill() {
        if(count == 0) {
            cout << "No bills to update!\n";
            return;
        }
        string id;
        cout << "Enter Bill ID to update: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(bills[i].getBillID() == id) {
                cout << "Re-enter bill details:\n";
                cout << "Update not fully implemented (requires dependencies)\n";
                return;
            }
        }
        cout << "Bill ID not found!\n";
    }
    
    void deleteBill() {
        if(count == 0) {
            cout << "No bills to delete!\n";
            return;
        }
        string id;
        cout << "Enter Bill ID to delete: "; cin >> id;
        for(int i=0; i<count; i++) {
            if(bills[i].getBillID() == id) {
                for(int j=i; j<count-1; j++) bills[j] = bills[j+1];
                count--;
                cout << "Bill deleted!\n";
                return;
            }
        }
        cout << "Bill ID not found!\n";
    }
};

// ================= File Handling Functions =================
void saveAllData(StaffCollection& sc, InvitationCollection& ic, VenueCollection& vc,
                 HostCollection& hc, ServiceCollection& svc) {
    ofstream outFile("event_data.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    
    sc.saveToFile(outFile);
    ic.saveToFile(outFile);
    vc.saveToFile(outFile);
    hc.saveToFile(outFile);
    svc.saveToFile(outFile);
    
    outFile.close();
    cout << "Data saved successfully!\n";
}

void loadAllData(StaffCollection& sc, InvitationCollection& ic, VenueCollection& vc,
                 HostCollection& hc, ServiceCollection& svc) {
    ifstream inFile("event_data.txt");
    if (!inFile) {
        cerr << "Error opening file for reading! Starting with empty data." << endl;
        return;
    }
    
    sc.loadFromFile(inFile);
    ic.loadFromFile(inFile);
    vc.loadFromFile(inFile);
    hc.loadFromFile(inFile);
    svc.loadFromFile(inFile);
    
    inFile.close();
    cout << "Data loaded successfully!\n";
}

// ================= Updated Management Functions =================
void manageHosts(HostCollection& hc) { 
    int choice;
    do {
        cout << "\nHost Management\n1. Add Host\n2. Display All\n3. Update Host\n4. Delete Host\n5. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) hc.addHost();
        else if(choice == 2) hc.displayAll();
        else if(choice == 3) hc.updateHost();
        else if(choice == 4) hc.deleteHost();
    } while(choice != 5);
}

void manageVenues(VenueCollection& vc) { 
    int choice;
    do {
        cout << "\nVenue Management\n1. Add Venue\n2. Display All\n3. Update Venue\n4. Delete Venue\n5. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) vc.addVenue();
        else if(choice == 2) vc.displayAll();
        else if(choice == 3) vc.updateVenue();
        else if(choice == 4) vc.deleteVenue();
    } while(choice != 5);
}

void manageServices(ServiceCollection& sc) { 
    int choice;
    do {
        cout << "\nService Management\n1. Add Custom Service\n2. Add Predefined Service\n3. Display All\n4. Update Service\n5. Delete Service\n6. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) sc.addService();
        else if(choice == 2) {
            sc.displayPredefinedServices();
            int serviceChoice;
            cout << "Select service to add (1-5): ";
            cin >> serviceChoice;
            if(serviceChoice >= 1 && serviceChoice <= 5) {
                sc.addPredefinedService(serviceChoice - 1);
            } else {
                cout << "Invalid selection!\n";
            }
        }
        else if(choice == 3) sc.displayAll();
        else if(choice == 4) sc.updateService();
        else if(choice == 5) sc.deleteService();
    } while(choice != 6);
}

void manageStaff(StaffCollection& sc) { 
    int choice;
    do {
        cout << "\nStaff Management\n1. Add Staff\n2. Display All\n3. Update Staff\n4. Delete Staff\n5. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) sc.addStaff();
        else if(choice == 2) sc.displayAll();
        else if(choice == 3) sc.updateStaff();
        else if(choice == 4) sc.deleteStaff();
    } while(choice != 5);
}

void manageInvitations(InvitationCollection& ic) { 
    int choice;
    do {
        cout << "\nInvitation Management\n1. Add Invitation\n2. Display All\n3. Generate Multiple Invitations\n4. Update Invitation\n5. Delete Invitation\n6. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) ic.addInvitation();
        else if(choice == 2) ic.displayAll();
        else if(choice == 3) {
            int numGuests;
            cout << "Enter number of guests: ";
            cin >> numGuests;
            ic.generateInvitations(numGuests);
        }
        else if(choice == 4) ic.updateInvitation();
        else if(choice == 5) ic.deleteInvitation();
    } while(choice != 6);
}

void manageEvents(EventCollection& ec, HostCollection& hc, VenueCollection& vc, ServiceCollection& sc, InvitationCollection& ic) { 
    int choice;
    do {
        cout << "\nEvent Management\n1. Add Event\n2. Display All\n3. Update Event\n4. Delete Event\n5. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) {
            if(hc.getCount() == 0 || vc.getLast() == NULL || sc.getLast() == NULL || ic.getLast() == NULL) {
                cout << "Required components missing! Add at least one Host, Venue, Service, and Invitation first.\n";
                continue;
            }
            
            // Service selection
            char serviceChoice;
            cout << "Do you want to add a new service? (y/n): ";
            cin >> serviceChoice;
            if(serviceChoice == 'y' || serviceChoice == 'Y') {
                int serviceOption;
                cout << "1. Add custom service\n2. Choose predefined service\nChoice: ";
                cin >> serviceOption;
                
                if(serviceOption == 1) {
                    sc.addService();
                } else if(serviceOption == 2) {
                    sc.displayPredefinedServices();
                    int serviceSelect;
                    cout << "Select service to add (1-5): ";
                    cin >> serviceSelect;
                    if(serviceSelect >= 1 && serviceSelect <= 5) {
                        sc.addPredefinedService(serviceSelect - 1);
                    } else {
                        cout << "Invalid selection! Adding custom service instead.\n";
                        sc.addService();
                    }
                } else {
                    cout << "Invalid option! Adding custom service.\n";
                    sc.addService();
                }
                cout << "New service added successfully!\n";
            }
            
            // Invitations
            char invChoice;
            cout << "Do you want to add new invitations? (y/n): ";
            cin >> invChoice;
            if(invChoice == 'y' || invChoice == 'Y') {
                int numGuests;
                cout << "Enter number of guests: ";
                cin >> numGuests;
                ic.generateInvitations(numGuests);
            }
            
            Event newEvent;
            newEvent.getInput(vc.getLast(), hc.getLast(), sc.getLast(), ic.getLast());
            
            // Get number of guests
            int numGuests;
            cout << "Enter total number of guests: ";
            cin >> numGuests;
            newEvent.setNumGuests(numGuests);
            
            ec.addEvent(newEvent);
            cout << "Event added successfully!\n";
        }
        else if(choice == 2) ec.displayAll();
        else if(choice == 3) ec.updateEvent();
        else if(choice == 4) ec.deleteEvent();
    } while(choice != 5);
}

void manageBills(BillCollection& bc, EventCollection& ec) { 
    int choice;
    do {
        cout << "\nBill Management\n1. Generate Bill for Last Event\n2. Display All\n3. Update Bill\n4. Delete Bill\n5. Back\nChoice: ";
        cin >> choice;
        if(choice == 1) {
            if(ec.getCount() > 0) {
                Event* lastEvent = ec.getLast();
                Bill* generatedBill = lastEvent->createBill();
                bc.addBill(*generatedBill);
                cout << "Bill generated successfully!\n";
            } else {
                cout << "No events available to generate bill!\n";
            }
        }
        else if(choice == 2) bc.displayAll();
        else if(choice == 3) bc.updateBill();
        else if(choice == 4) bc.deleteBill();
    } while(choice != 5);
}

int main() {
    HostCollection hc;
    VenueCollection vc;
    ServiceCollection sc;
    StaffCollection stc;
    InvitationCollection ic;
    EventCollection ec;
    BillCollection bc;

    // Load existing data at startup
    loadAllData(stc, ic, vc, hc, sc);

    int choice;
    do {
        cout << "\nEvent Ticketing System\n";
        cout << "1. Manage Hosts\n2. Manage Venues\n3. Manage Services\n4. Manage Staff\n5. Manage Invitations\n";
        cout << "6. Manage Events\n7. Manage Bills\n8. Save Data\n9. Load Data\n10. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: manageHosts(hc); break;
            case 2: manageVenues(vc); break;
            case 3: manageServices(sc); break;
            case 4: manageStaff(stc); break;
            case 5: manageInvitations(ic); break;
            case 6: manageEvents(ec, hc, vc, sc, ic); break;
            case 7: manageBills(bc, ec); break;
            case 8: saveAllData(stc, ic, vc, hc, sc); break;
            case 9: loadAllData(stc, ic, vc, hc, sc); break;
            case 10: 
                saveAllData(stc, ic, vc, hc, sc); 
                cout << "Exiting...\n"; 
                break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 10);
    
    return 0;
}