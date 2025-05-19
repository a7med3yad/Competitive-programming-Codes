void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> tmp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            tmp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        tmp.push_back(arr[i++]);
    }

    while (j <= end) {
        tmp.push_back(arr[j++]);
    }

    for (int k = 0; k < tmp.size(); ++k) {
        arr[start + k] = tmp[k];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
