class quickSort{
public:
	void arraySort(int arr[], int lside, int rside){      //sorts an arrray using quick sort  
		//partition(arr,lside,rside);
		int x = partition(arr,lside,rside);     //fixes the pivot 
		if (lside<x)
		{
			arraySort(arr,lside,x);         //recursively sorts the left array after partition 
		}
		
		if ((x+2)<rside){           
			arraySort(arr,x+2,rside);       //recursively sorts the right array after partition
		}
		
		for(int i =0; i<5; i++){
			cout << arr[i] << endl;         //prints the elements after sorting
		}

		cout << endl;
	}

	

	int partition(int arr[], int lside, int rside){     //partition of an array into two
		
		int i = lside-1;
		int pivot = arr[rside];   
      
		for (int j = lside; j <= rside; ++j)
		{
			if(arr[j]<pivot){         //increase i by 1 and then swaps arr[i] and arr[j] if arr[j] is smaller than pivot
				i++;
				int a = arr[j];
				int b = arr[i];
				arr[i] = a;
				arr[j] = b;
			}
		}

		int	a = arr[rside];         //finally swaps the pivot and the element arr[i+1]
		int b = arr[i+1];
		arr[i+1] = a;
		arr[rside] = b;

		return i;
	}


};
