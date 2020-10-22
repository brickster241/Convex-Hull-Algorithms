import sys
import pygame
import time


def create_canvas(lines, screen, points):
    screen.fill(BLACK)
    for i in range(0, SCREEN_LENGTH, 25):
        pygame.draw.line(screen, WHITE, (i, 0), (i, SCREEN_WIDTH))
    pygame.display.flip()
    for i in range(0, SCREEN_WIDTH, 25):
        pygame.draw.line(screen, WHITE, (0, i), (SCREEN_LENGTH, i))
    pygame.display.flip()
    for p1, p2 in lines:
        pygame.draw.line(screen, (0, 255, 0), p1, p2, 2)
    pygame.display.flip()
    for pos in points:
        pygame.draw.circle(screen, (255, 255, 0), pos, 5)
    pygame.display.flip()


def Cross_Product(last, middle, first):
    last_x, last_y = last[0], 600 - last[1]
    middle_x, middle_y = middle[0], 600 - middle[1]
    first_x, first_y = first[0], 600 - first[1]
    # make the vectors appropriately - First and Middle, First and Last
    x1, y1 = middle_x - first_x, middle_y - first_y
    x2, y2 = last_x - first_x, last_y - first_y
    return x2 * y1 - x1 * y2


def CalculateHull(ConvexHull, LINES, SCREEN, POINTS, GREEN, start, end, step):
    pygame.display.flip()
    time.sleep(1)
    for i in range(start, end, step):
        ConvexHull.append(POINTS[i])
        LINES.append((ConvexHull[-1], POINTS[i]))
        pygame.draw.line(SCREEN, GREEN, ConvexHull[-2], ConvexHull[-1], 2)
        LINES.append((ConvexHull[-2], ConvexHull[-1]))
        pygame.display.flip()
        time.sleep(1)
        while len(ConvexHull) >= 3 and Cross_Product(ConvexHull[-1], ConvexHull[-2],
                                                     ConvexHull[-3]) <= 0:
            # delete the middle element
            LINES.remove((ConvexHull[-2], ConvexHull[-1]))
            create_canvas(LINES, SCREEN, POINTS)
            time.sleep(1)
            LINES.remove((ConvexHull[-3], ConvexHull[-2]))
            create_canvas(LINES, SCREEN, POINTS)
            time.sleep(1)
            pygame.draw.line(SCREEN, GREEN, ConvexHull[-3], ConvexHull[-1], 2)
            LINES.append((ConvexHull[-3], ConvexHull[-1]))
            pygame.display.flip()
            time.sleep(1)
            ConvexHull.pop(-2)

        pygame.display.flip()


lines = []
points = []
SCREEN_WIDTH = 600
SCREEN_LENGTH = 800
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
size = (SCREEN_LENGTH, SCREEN_WIDTH)
screen = pygame.display.set_mode(size)
pygame.display.set_caption('Convex Hull Algorithm')
create_canvas(lines, screen, points)

N = 10
count = 0
running = True
while running:
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            sys.exit()

        if event.type == pygame.MOUSEBUTTONDOWN and count < N:
            count += 1
            pos = pygame.mouse.get_pos()
            points.append(pos)
            pygame.draw.circle(screen, YELLOW, pos, 5)

        pygame.display.flip()

        if len(points) != N:
            continue
        else:
            # all points are displayed on the Screen
            points.sort(key=lambda x: x[0])
            running = False
            UpperConvexHull = [points[0], points[1]]
            lines = [(UpperConvexHull[0], UpperConvexHull[1])]
            pygame.draw.line(screen, GREEN, UpperConvexHull[0], UpperConvexHull[1], 2)
            CalculateHull(UpperConvexHull, lines, screen, points, GREEN, 2, N, 1)

            LowerConvexHull = [points[-1], points[-2]]
            lines.append((LowerConvexHull[0], LowerConvexHull[1]))
            pygame.draw.line(screen, GREEN, LowerConvexHull[0], LowerConvexHull[1], 2)
            CalculateHull(LowerConvexHull, lines, screen, points, GREEN, N - 3, -1, -1)
            time.sleep(5)
            break
