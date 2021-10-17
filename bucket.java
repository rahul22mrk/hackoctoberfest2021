import java.util.*;

class bucket {

	static void bucketSort(float arr[], int n)
	{
		if (n <= 0)
			return;

		Vector<Float>[] buckets = new Vector[n];

		for (int i = 0; i < n; i++) {
			buckets[i] = new Vector<Float>();
		}


		for (int i = 0; i < n; i++) {
			float idx = arr[i] * n;
			buckets[(int)idx].add(arr[i]);
		}


		for (int i = 0; i < n; i++) {
			Collections.sort(buckets[i]);
		}


		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < buckets[i].size(); j++) {
				arr[index++] = buckets[i].get(j);
			}
		}
	}

	public static void main(String args[])
	{
		float arr[] = { (float)0.3897, (float)0.5654,
						(float)0.6356, (float)0.14234,
						(float)0.675665, (float)0.34934 };

		int n = arr.length;
		bucketSort(arr, n);

		for (float el : arr) {
			System.out.print(el + " ");
		}
	}
}
