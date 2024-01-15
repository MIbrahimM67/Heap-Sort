
#include <iostream>
void reHeapDown(int parent,int Array[9],int size)
{
    int lc, rc, mc;
    while (parent < size)
    {
        lc = parent * 2 + 1; // finding left child
        rc = lc + 1; // finding right child
        mc = lc;
        if (lc < size)
        {
            if (rc < size)
            {
                if (Array[rc] > Array[mc])
                {
                    mc = rc;  
                }
            }
            if (Array[parent] < Array[mc])
            {
                std::swap(Array[parent], Array[mc]); // swapping if the parent is less than the max child 
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        parent = mc;
    }
}

int main()
{    
    int Array[10] = { 2,1,3,4,5,2,6,9,73,7 }; // having random values, you can take any values
     
    //step 1, we heapify the array
    int size = 10;

    int i = 9;// as size n is 10 so we taking the value of i as n-1
    int lc, rc, mc;
        while (i >= 0)
        {
            lc = i * 2 + 1; // finding left child
            rc = lc + 1; // finding right child
            mc = lc;
            if (lc < size)
            {
                reHeapDown(i, Array,size); // applying reheapdown to all the nodes below

            }
            i--;
        }
        std::cout << " Printing Values after converting it to heap ";
        for (int i = 0; i < 10; i++)
        {
            std::cout << Array[i] << " "; // 
        }

        //step : 2 , we sort the heap

        int tempsize = size;
            while (tempsize>0)
            {
                std::swap(Array[0], Array[tempsize - 1]);
                reHeapDown(0, Array, tempsize-1); // we always reduce the size by -1 after swapping so that sorting could be done and then we heapify the array
                tempsize--;

            }
            std::cout << std::endl;
            std::cout << " Printing Values after Sorting ";
            for (int i = 0; i < 10; i++)
            {
                std::cout << Array[i] << " "; // after sorting, printing the values
            }


} 

