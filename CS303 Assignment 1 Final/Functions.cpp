#include "Functions.h"

using namespace std;


void menu()
{
    //Menu of choices for the user to choose 
    cout << "What would you like to do with array?" << endl;
    cout << "1. Check for integer in array?" << endl;
    cout << "2. Modify value of integer?" << endl;
    cout << "3. Add new integer to array?" << endl;
    cout << "4. Replace integer in array with 0 or delete." << endl;
    cout << "5. Print out array" << endl << endl;
    cout << "Pick 1-4: ";
}

int search(int arr[], int user_size, int x)
{
    int i;
    for (i = 0; i < user_size; i++)    //Simple linear search to check for integer in array
        if (arr[i] == x)
            return i;
    return -1;
}

void modify(int arr[], int low, int size)
{
    int mod_index;
    int mod_num;
    cin.exceptions(ios_base::failbit);

    while (true)
    {
        try {
            cout << endl;
            cout << "What index in the array would you like to modify ==> ";
            cin >> mod_index;
            if ((mod_index < 0) || (mod_index > size - 1))  //If user index is not within array size will throw an out of range error
            {
                throw std::out_of_range("Out of Range");
            }

            else
                break;

        }

        catch (ios_base::failure& ex) //Catch in result of user input being incorrect format.
        {
            cout << "You did not enter the correct format. Try again";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }

        catch (std::out_of_range)
        {
            cout << "You number is out of range, must be between 0-" << size - 1 << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');

        }
    }

    while (true)
    {
        try
        {
            cout << "What number would you like to replace at that index ==> ";
            cin >> mod_num;
            break;
        }

        catch (ios_base::failure& ex)
        {
            cout << "You entered the incorrect format. Try again";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }

    }

    int old = arr[mod_index];

    arr[mod_index] = mod_num;

    cout << "The old number was ==> " << old << endl;
    cout << "The new number is now ==> " << mod_num << endl;
}


void insertElement(int arr[], int user_size)
{
    int insertNum;
    cin.exceptions(ios_base::failbit);

    while (true)
    {
        try
        {
            cout << "What number would you like to add at the end ==> ";
            cin >> insertNum;
            arr[user_size - 1] = insertNum;

            break;
        }

        catch (ios_base::failure& ex)
        {
            cout << "Incorrect format, try again.";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }


}

void deleteInt(int arr[], int userindex, int user_size)
{
    for (int i = userindex; i < user_size - 1; i++)
    {
        arr[i] = arr[i + 1];                //May not be the most efficent but loop shifts. 
    }


}

void replaceElement(int arr[], int userIndex, char userChoice, int size)
{
    /* Will loop then swap out the new element based on the index or if 0 just replace the first*/
    if (userChoice == '0')
    {
        arr[userIndex] = 0;
    }

    if (userChoice == 'D' || userChoice == 'd')
    {
        for (int i = userIndex; i < size - 1; i++)
        {
            arr[i] == arr[i + 1];

        }

    }
}


//Print array out for visual use.
void printArray(int arr[], int user_size)
{
    for (int i = 0; i < user_size; i++)
    {
        cout << arr[i] << " ";
    }
}