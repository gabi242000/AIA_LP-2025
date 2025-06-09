import pygame
import json
import time

# Inițializare Pygame
pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Simulare Trafic - Design Modern")

# Culori
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (220, 20, 60)
GREEN = (0, 255, 0)
BLUE = (30, 144, 255)
YELLOW = (255, 215, 0)
ORANGE = (255, 140, 0)
GRAY = (40, 40, 40)
ROAD = (60, 60, 60)
LINE = (180, 180, 180)

# Font
font = pygame.font.SysFont('Arial', 28, bold=True)

def draw_scene(cars, traffic_lights):
    screen.fill(GRAY)

    # Desenează drumul
    pygame.draw.rect(screen, ROAD, (0, 100, 800, 400))
    for i in range(120, 500, 80):
        pygame.draw.line(screen, LINE, (0, i), (800, i), 2)

    # Titlu
    title = font.render("Simulare Trafic - Apasă 'R' pentru Reset", True, WHITE)
    screen.blit(title, (20, 20))

    # Semafoare
    for light in traffic_lights:
        pygame.draw.rect(screen, (120, 120, 120), (light["x"], light["y"], 30, 90))
        if light["green_ns"]:
            pygame.draw.circle(screen, GREEN, (light["x"] + 15, light["y"] + 45), 10)
        else:
            pygame.draw.circle(screen, RED, (light["x"] + 15, light["y"] + 45), 10)



    # Mașini
    car_colors = [BLUE, YELLOW, ORANGE]
    for idx, car in enumerate(cars):
        color = car_colors[idx % len(car_colors)]
        pygame.draw.rect(screen, color, (car["x"], car["y"], 50, 25))
        pygame.draw.circle(screen, WHITE, (car["x"] + 50, car["y"] + 8), 3)
        pygame.draw.circle(screen, WHITE, (car["x"] + 50, car["y"] + 18), 3)

    pygame.display.flip()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                with open("sim.json", "w") as f:
                    f.write('''{
  "cars": [
    { "id": 1, "x": 50, "y": 150 },
    { "id": 2, "x": 50, "y": 300 },
    { "id": 3, "x": 50, "y": 450 }
  ],
  "traffic_lights": [
    { "x": 400, "y": 140, "green_ns": true },
    { "x": 400, "y": 290, "green_ns": false },
    { "x": 400, "y": 440, "green_ns": true }
  ]
}''')

    with open("sim.json") as f:
        data = json.load(f)
        cars = data["cars"]
        traffic_lights = data["traffic_lights"]

    draw_scene(cars, traffic_lights)
    time.sleep(0.2)

pygame.quit()
