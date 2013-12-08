using System;

public class Love
{
	int sum = 0;
	int counter = 999;
	
	public static void Main()
	{
		while(counter != 0)
		{
			if(counter % 3 == 0 || counter % 5 == 0)
				sum += counter;
			counter--;
		}
		Console.WriteLine(sum);
	}
}