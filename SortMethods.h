// SortMethods.h : header file containing the different sorting algorithms, contained with their own namespaces
#ifndef SortMethods___
#define SortMethods___

namespace BubbleSort
{
	// sort algorithms, return value = number of comparisons
	int Sort(int* input, int length)
	{
		// if the list is small enough to not require sorting, leave
		if ( length <= 1 ) return 1;

		// create a holder for the number of comparisons
		int comparisons = 0;

		// in order to sort the whole algorithm, it needs to loop through the list for as many items as there are to sort
		// this requires a nested for loop
		for ( int i = 0; i < length - 1; i++ )
		{
			for ( int j = 0; j < length - 1; j++ )
			{
				comparisons++;

				// if current value (input[j]) is bigger than the one next to it...
				if ( input[j] > input[j + 1] )
				{
					// swap the values around
					input[j] = input[j] + input[j + 1];
					input[j + 1] = input[j] - input[j + 1];
					input[j] = input[j] - input[j + 1];
				}
			}
		}

		// return the number of comparisons made
		return comparisons;
	}
	int SortReverse(int* input, int length)
	{
		// if the list is small enough to not require sorting, leave
		if ( length <= 1 ) return 1;

		// create a holder for the number of comparisons
		int comparisons = 0;

		// in order to sort the whole algorithm, it needs to loop through the list for as many items as there are to sort
		// this requires a nested for loop
		for ( int i = 0; i < length - 1; i++ )
		{
			for ( int j = 0; j < length - 1; j++ )
			{
				comparisons++;

				// if current value (input[j]) is smaller than the one next to it...
				if ( input[j] < input[j + 1] )
				{
					// swap the values around
					input[j] = input[j] + input[j + 1];
					input[j + 1] = input[j] - input[j + 1];
					input[j] = input[j] - input[j + 1];
				}
			}
		}

		// return the number of comparisons made
		return comparisons;
	}
}

namespace InsertionSort
{
	// sort algorithms, return value = number of comparisons
	int Sort(int* input, int length)
	{
		// if the list is small enough to not require sorting, leave
		if ( length <= 1 ) return 1;

		// creates a holder for the list item and number of comparisons made
		int holder = 0;
		int comparisons = 0;

		// takes each value, and compares it to all previous items to see where it should be placed
		for ( int i = 0; i < length; i++ )
		{
			// store the value in a holder address
			holder = input[i];

			// compare it to all previous items in the list
			for ( int j = i - 1; j >= 0; j-- )
			{
				comparisons++;
				// if the holder value is smaller than the previous item, push it forward
				if ( holder < input[j] )
				{
					input[j + 1] = input[j];
					input[j] = holder;
				}
				// otherwise, the holder has found it's place, continue to next value
				else break;
			}
		}

		// return the number of comparisons to the caller
		return comparisons;
	}
	int SortReverse(int* input, int length)
	{
		// if the list is small enough to not require sorting, leave
		if ( length <= 1 ) return 1;

		// creates a holder for the list item and number of comparisons made
		int holder = 0;
		int comparisons = 0;

		// takes each value, and compares it to all previous items to see where it should be placed
		for ( int i = 0; i < length; i++ )
		{
			// store the value in a holder address
			holder = input[i];

			// compare it to all previous items in the list
			for ( int j = i - 1; j >= 0; j-- )
			{
				comparisons++;
				// if the holder value is bigger than the previous item, push it forward
				if ( holder > input[j] )
				{
					input[j + 1] = input[j];
					input[j] = holder;
				}
				// otherwise, the holder has found it's place, continue to next value
				else break;
			}
		}

		// return the number of comparisons to the caller
		return comparisons;
	}
}

namespace QuickSort
{
	// sort algorithms, return value = number of comparisons
	int Sort(int* input, int leftStart, int rightStart)
	{
		// if list has 0 or 1 elements, it's already sorted
		if ( rightStart - leftStart <= 0 ) return 1;
		
		// select middle item as pivot
		int pivot = input[(leftStart + rightStart) / 2];

		// identify start positions of the quick sort
		int leftPtr = leftStart;
		int rightPtr = rightStart;

		// create containers for holding data
		int holder = 0;
		int comparisons = 0;

		do
		{
			// move right pointer until an out of place item is found
			while ( input[rightPtr] > pivot ) { comparisons++; rightPtr--; }
			// move left pointer until an out of place item is found
			while ( input[leftPtr] < pivot ) { comparisons++; leftPtr++; }

			// swap the two values
			if ( rightPtr >= leftPtr )
			{
				comparisons++;
				holder = input[leftPtr];
				input[leftPtr] = input[rightPtr];
				input[rightPtr] = holder;
				leftPtr++;
				rightPtr--;
			}
		} while ( leftPtr < rightPtr );
	
		// sort sublists (summing the total number of comparisons made)
		if ( rightPtr > leftStart ) comparisons += Sort(input, leftStart, rightPtr);
		if ( leftPtr < rightStart ) comparisons += Sort(input, leftPtr, rightStart);

		// return the number of comparisons made
		return comparisons;
	}
	int SortReverse(int* input, int leftStart, int rightStart)
	{
		// if list has 0 or 1 elements, it's already sorted
		if ( rightStart - leftStart <= 0 ) return 1;
		
		// select middle item as pivot
		int pivot = input[(leftStart + rightStart) / 2];

		// identify start positions of the quick sort
		int leftPtr = leftStart;
		int rightPtr = rightStart;

		// create containers for holding data
		int holder = 0;
		int comparisons = 0;

		do
		{
			// move right pointer until an out of place item is found
			while ( input[rightPtr] < pivot ) { comparisons++; rightPtr--; }
			// move left pointer until an out of place item is found
			while ( input[leftPtr] > pivot ) { comparisons++; leftPtr++; }

			// swap the two values
			if ( rightPtr >= leftPtr )
			{
				comparisons++;
				holder = input[leftPtr];
				input[leftPtr] = input[rightPtr];
				input[rightPtr] = holder;
				leftPtr++;
				rightPtr--;
			}
		} while ( leftPtr < rightPtr );
	
		// sort sublists (summing the total number of comparisons made)
		if ( rightPtr > leftStart ) comparisons += SortReverse(input, leftStart, rightPtr);
		if ( leftPtr < rightStart ) comparisons += SortReverse(input, leftPtr, rightStart);

		// return the number of comparisons made
		return comparisons;
	}
}

#endif