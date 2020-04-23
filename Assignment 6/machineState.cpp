include "machineState.h"

int No_Charge::pick(int humanCharge)
{
    if(humanCharge == 0)
    {
        return 0; // charge
    }
    else if(humanCharge == 1)
    {
        return rand(2); // block or charge
    }
}

int Have_Charges1::pick(int humanCharge)
{
    if(humanCharge == 0)
    {
       return 0; // charge
    }
    if(humanCharge > 0)
    {
        return rand(3); // block or charge or fireball
    }
}

int action_state::pick(int humanCharge)
{
    if(state == No_Charge)
    {
        int choice = No_Charge.pick(humanCharge);
        if(choice == 0)
        {
            state = Have_Charges1;
            return choice;
        }
    }
}


