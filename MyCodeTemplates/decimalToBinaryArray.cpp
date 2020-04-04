int* decToBinary(int n)
{
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0)
	{

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	static int binaryNumber[32];

	for (int j = i - 1; j >= 0; j--)
	{
		binaryNumber[i-1-j]=binaryNum[j];
	}

	return binaryNumber;
}