def sort_points(points):
    sorted_points = sorted(points, key=lambda point: (point[0], point[1]))
    return sorted_points


N = int(input())
points = []

for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

sorted_points = sort_points(points)
for point in sorted_points:
    print(point[0], point[1])
