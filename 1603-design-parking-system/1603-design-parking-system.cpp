class ParkingSystem {
public:
    
    vector<int>slots;
    ParkingSystem(int big, int medium, int small) {
        slots.resize(4,0);
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }
    
    bool addCar(int carType) {
        
        if(slots[carType] != 0)
        {
            slots[carType]--;
            return true;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */