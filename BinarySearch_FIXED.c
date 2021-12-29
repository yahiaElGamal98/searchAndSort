/*INCLUSIONS*********************************/
#include<stdio.h>
#include<stdlib.h>
#include"BinarySearch.h"
#pragma warning(disable:4996)
/*MACROS*************************************/
#define FALSE 0
#define TRUE 1
#define NO_ITERATIONS 0
#define NOT_FOUND 255  //can't return -1 (unsigned int return)

/*FUNCTION IMPLEMENTATIONS*******************/
void swap(uint32_t* left, uint32_t* right)
{
   uint32_t u8_temp;       // temp variable for swapping
   u8_temp = *right;      // temp variable equal right
   *right = *left;         // right handside variable eqal left var
   *left = u8_temp;        //left variable equal temp
}

void sortAndCheck(uint32_t* arr, uint8_t size)
{
   uint8_t u8_traverseIndex   // used for moving in loop
      , u8_iterationIndex   //used for iterations 
      , u8_sortFlag=FALSE;   //used to check if array is sorted on first iteration
   for (u8_traverseIndex = 0; u8_traverseIndex < size-1; u8_traverseIndex++)
   {
      if (arr[u8_traverseIndex + 1] > arr[u8_traverseIndex])   //Iterate once to check if array is sorted
      {
         u8_sortFlag = FALSE;   //it doesn't need sorting all elements are in ascending order
         continue;
      }
      else
      {
         u8_sortFlag = TRUE;     //an element is out of order, it needs sorting
         break;
      }
   }
   if (u8_sortFlag) //sorting operation is done if it needs sorting
   {
      for (u8_iterationIndex = 0; u8_iterationIndex < size - 1; u8_iterationIndex++)
      {
         for (u8_traverseIndex = u8_iterationIndex + 1; u8_traverseIndex < size; u8_traverseIndex++)
         {
            if (arr[u8_traverseIndex] < arr[u8_iterationIndex])
            {
               swap(arr + u8_traverseIndex, arr + u8_iterationIndex);
            }
            else
            {
               continue;
            }
         }
      }
   }
   else  //it doesn't need sorting
   {
      printf("Array is already sorted.\n");
   }   
}
uint8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t searchElement)
{
   uint8_t u8_start = 0    //start search index
      , u8_end = size - 1     //end search index
      , u8_mid = (uint8_t)((u8_start + u8_end) / 2);   //middle search index
   sortAndCheck(arr, size);
   while (arr[u8_mid] != searchElement)   //while the middle element doesn't equal search element
   {
      if (searchElement < arr[u8_mid])    // if search element is less than mid index element
      {
         u8_end = u8_mid - 1;  //the end is now just before the mid element
         u8_mid = (uint8_t)((u8_start + u8_end) / 2);    // the mid is recalculated
         if (u8_start > u8_end)     //check if start index is more than the end (Element not found)
         {
            return NOT_FOUND;    
         }
      }
      else if (searchElement > arr[u8_mid])  //if search element is more than the mid element
      {
         u8_start = u8_mid + 1;     //start is now just after the mid element
         u8_mid = (uint8_t)((u8_start + u8_end) / 2);    //mid recalculated
         if (u8_start > u8_end)
         {
            return NOT_FOUND;    //check if start index is more than the end (Element not found)
         }
      }
   }
   return u8_mid;    //return element index
}
void main()
{
   uint32_t u32_arr[] = { 15,87,30,21,47,69,201,78 };   //insert your Array here (NO MORE THAN 255 ELEMENTS)
   uint32_t u32_searchNum = 87;     //search for any element here
   uint8_t u8_size = sizeof(u32_arr)/sizeof(uint32_t);   //calculating size based on input
   uint8_t u8_index;    //variable to print the array after sorting for debugging
   uint8_t u8_returnIndex;    //variable to store index of found element
   u8_returnIndex = binarySearch(u32_arr,u8_size, u32_searchNum);
   if (u8_returnIndex != NOT_FOUND)
   {
      printf("The search element %d is present at index (%d)\n ",u32_searchNum, u8_returnIndex);
   }
   else
   {
      printf("Element not found!\n");
   }
   printf("\n");
   for (u8_index = 0; u8_index < u8_size; u8_index++)    
   {
      printf("Array Element %d: %d \n", u8_index, u32_arr[u8_index]);
   }
   system("PAUSE");
}