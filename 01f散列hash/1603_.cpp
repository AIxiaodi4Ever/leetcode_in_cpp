class ParkingSystem {
public:
    int typeSlots[3];

    ParkingSystem(int big, int medium, int small) {
        typeSlots[0] = big;
        typeSlots[1] = medium;
        typeSlots[2] = small;
    }
    
    bool addCar(int carType) {
        if (typeSlots[carType - 1] == 0)
            return false;
        --typeSlots[carType - 1];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */