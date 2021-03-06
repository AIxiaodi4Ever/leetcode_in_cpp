// ����Ϊ�鲢����
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int temp_array[nums1Size];
    int i = 0, j = 0, k = 0;

    // �ȱ�����m��n
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

    // ֮����һ����ʣ��Ԫ�ؼ���
    while (i < m)
    {
        temp_array[k++] = nums1[i++];
    }
    while (j < n)
    {
        temp_array[k++] = nums2[j++];
    }
    
    // ����temp_array��nums1
    for (i = 0; i < k; i++)
    {
        nums1[i] = temp_array[i];
    }    
}