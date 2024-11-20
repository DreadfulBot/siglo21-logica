namespace RiskyWorks
{
  template <typename T>
  class MergeSort
  {
  public:
    static void merge(vector<T> &vec, int left, int mid, int right)
    {
      int i, j, k;
      int n1 = mid - left + 1;
      int n2 = right - mid;

      // Create temporary vectors
      vector<T> leftVec(n1), rightVec(n2);

      // Copy data to temporary vectors
      for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
      for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

      // Merge the temporary vectors back into vec[left..right]
      i = 0;
      j = 0;
      k = left;
      while (i < n1 && j < n2)
      {
        if (leftVec[i] <= rightVec[j])
        {
          vec[k] = leftVec[i];
          i++;
        }
        else
        {
          vec[k] = rightVec[j];
          j++;
        }
        k++;
      }

      // Copy the remaining elements of leftVec[], if any
      while (i < n1)
      {
        vec[k] = leftVec[i];
        i++;
        k++;
      }

      // Copy the remaining elements of rightVec[], if any
      while (j < n2)
      {
        vec[k] = rightVec[j];
        j++;
        k++;
      }
    }

    // The subarray to be sorted is in the index range [left..right]
    static void sort(vector<T> &vec, int left, int right)
    {
      if (left < right)
      {
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        sort(vec, left, mid);
        sort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
      }
    }
  };
}