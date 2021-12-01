
enum CarType
{
    BIG = 1,
    MEDIUM,
    SMALL
};

class ParkingSystem
{
private:
    int big_slots;
    int medium_slots;
    int small_slots;

public:
    ParkingSystem(int big, int medium, int small)
    {
        big_slots = big;
        medium_slots = medium;
        small_slots = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case BIG:
            if (big_slots > 0)
            {
                big_slots--;
                return true;
            }
            break;
        case MEDIUM:
            if (medium_slots > 0)
            {
                medium_slots--;
                return true;
            }
            break;
        case SMALL:
            if (small_slots > 0)
            {
                small_slots--;
                return true;
            }
            break;

        default:
            return false;
        }

        return false;
    }
};
