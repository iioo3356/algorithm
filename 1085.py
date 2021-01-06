x, y, w, h = map(int, input().split())
x_dist = min(w-x, x-0)
y_dist = min(h-y, y-0)
print(min(x_dist, y_dist))
