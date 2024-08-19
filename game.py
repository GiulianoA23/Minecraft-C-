import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

# Window dimensions
WIDTH, HEIGHT = 800, 600

# Block dimensions
BLOCK_SIZE = 1.0

# Colors
WHITE = (1.0, 1.0, 1.0)
BLACK = (0.0, 0.0, 0.0)

class Block:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
        self.type = random.choice(['grass', 'dirt', 'stone'])

    def draw(self):
        if self.type == 'grass':
            glColor3f(0.0, 1.0, 0.0)
        elif self.type == 'dirt':
            glColor3f(0.55, 0.27, 0.0)
        elif self.type == 'stone':
            glColor3f(0.5, 0.5, 0.5)
        glBegin(GL_QUADS)
        glVertex3f(self.x, self.y, self.z)
        glVertex3f(self.x + BLOCK_SIZE, self.y, self.z)
        glVertex3f(self.x + BLOCK_SIZE, self.y, self.z + BLOCK_SIZE)
        glVertex3f(self.x, self.y, self.z + BLOCK_SIZE)
        glEnd()

class Player:
    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0

    def move(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

def main():
    pygame.init()
    display = (WIDTH, HEIGHT)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0, 0.0, -5)

    blocks = []
    for x in range(-10, 11):
        for y in range(-10, 11):
            for z in range(-10, 11):
                blocks.append(Block(x, y, z))

    player = Player()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_w:
                    player.move(0, 0, 1)
                elif event.key == pygame.K_s:
                    player.move(0, 0, -1)
                elif event.key == pygame.K_a:
                    player.move(-1, 0, 0)
                elif event.key == pygame.K_d:
                    player.move(1, 0, 0)
                elif event.key == pygame.K_q:
                    player.move(0, 1, 0)
                elif event.key == pygame.K_e:
                    player.move(0, -1, 0)

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        glPushMatrix()
        glTranslatef(player.x, player.y, player.z)
        glRotatef(0, 0, 1, 0)
        glRotatef(0, 1, 0, 0)
        glRotatef(0, 0, 0, 1)

        for block in blocks:
            block.draw()

        glPopMatrix()

        pygame.display.flip()
        pygame.time.wait(10)

main()