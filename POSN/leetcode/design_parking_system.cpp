class ParkingSystem {
public:
    int a[3];
    ParkingSystem(int big, int medium, int small) {
        a[0]=big,a[1]=medium,a[2]=small;
    }
    
    bool addCar(int carType) {
        carType--;
        if(a[carType]){
            a[carType]--;
            return true;
        }
        else return false;
    }
};