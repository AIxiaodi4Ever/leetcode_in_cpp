// 本质为归并排序
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int temp_array[nums1Size];
    int i = 0, j = 0, k = 0;

    // 先遍历完m或n
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            temp_array[k++] = nums1[i++];
        }
        else
        {
            temp_array[k++] = nums2[j++];
        }
    }

    // 之后将另一数组剩余元素加入
    while (i < m)
    {
        temp_array[k++] = nums1[i++];
    }
    while (j < n)
    {
        temp_array[k++] = nums2[j++];
    }
    
    // 复制temp_array至nums1
    for (i = 0; i < k; i++)
    {
        nums1[i] = temp_array[i];
    }    
}