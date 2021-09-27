#include <bits/stdc++.h>
using namespace std;

struct point {
    float x;
    float y;
};

bool compareX(point p1, point p2) {
    return p1.x < p2.x;
}
bool compareY(point p1, point p2) {
    return p1.y < p2.y;
}

void heapify(point arr[], int n, int i, bool (*compare)(point, point)) {
    int j = -1;
    while (i != j) {
        j = i;
        int left_idx  = 2 * i + 1;
        int right_idx = 2 * i + 2;
        if (left_idx < n && (*compare)(arr[i], arr[left_idx]))
            i = left_idx  ;
        if (right_idx < n && (*compare)(arr[i], arr[right_idx]))
            i = right_idx;
        swap(arr[i], arr[j]);
    }
}

void heap_sort(point arr[], int n, bool (*compare)(point, point)) {
    for (int i = n / 2 ; i >= 0 ; i--)
        heapify(arr, n, i, compare);
    for (int i = n - 1 ; i >= 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, compare);
    }
}

float dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float brute_force(point p[], int n) {
    float res = FLT_MAX;  
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            res = min(res, dist(p[i], p[j]));
    }
    return res;  
}

float strip_closest(point p[], int n, float d) {
    float res = d;
    heap_sort(p, n, &compareY);
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && (p[j].y - p[i].y) < res) {
            res = min(res, dist(p[i], p[j]));
            j++;
        }
    }
    return res;
}

float get_closest_pair(point p[], int n) {
    if (n <= 3) {
        return brute_force(p, n);
    }
    int mid = n / 2;
    float d_left  = get_closest_pair(p, mid);
    float d_right = get_closest_pair(p + mid, n - mid);
    float d = min(d_left, d_right);

    point *strip = new point[n];
    int j = 0;
    point mid_point = p[mid];
    for (int i = 0; i < n; i++) {
        if (abs(p[i].x - mid_point.x) < d) {
            strip[j] = p[i];
            j++;
        }
    }
    return min(d, strip_closest(strip, j, d));
}

float closest_pair(point p[], int n) {
    heap_sort(p, n, &compareX);
    return get_closest_pair(p, n);
}

int main() {

    int n = 6;
    point p[]  = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << "The smallest distance is " << closest_pair(p, n);

}