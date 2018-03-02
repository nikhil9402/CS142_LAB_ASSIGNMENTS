void binarySearch(int arr[], int lside, int rside, int key){        //search an element in the array
	int mid = (lside+rside)/2;          //declares a pivot

	if(key<=arr[rside] && key>=arr[lside]){

		if (arr[mid]==key)
		{
			cout << "Key found at " << mid << endl;     //If key is found
		}
                                                        //If key is not found, calls the binarySearch function again
		else if (arr[mid] > key){
			binarySearch(arr,lside,mid-1,key);          //If key is left to the pivot
		}

		else if (arr[mid] < key){
			binarySearch(arr,mid+1,rside,key);          //If key is right to the pivot
		}
 	}

	else
	{
		cout << "Key not found" << endl;                //If key is not found
	}
}
