double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int targetIDX = total / 2;

    int mergedArray[total];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            mergedArray[k] = nums1[i];
            i++;
        } else {
            mergedArray[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (i < nums1Size) {
        mergedArray[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2Size) {
        mergedArray[k] = nums2[j];
        j++;
        k++;
    }

    if (total % 2 == 0) {
        return (mergedArray[targetIDX] + mergedArray[targetIDX - 1]) / 2.0;
    } else {
        return mergedArray[targetIDX];
    }
}