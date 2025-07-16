import os
import svgwrite

def create_metal_plate(path):
    dwg = svgwrite.Drawing(path, size=(256, 256))
    dwg.add(dwg.rect(insert=(0, 0), size=('100%', '100%'), fill='#808080'))
    # Add rivets
    for x in range(32, 256, 64):
        for y in range(32, 256, 64):
            dwg.add(dwg.circle(center=(x, y), r=8, fill='#606060'))
    dwg.save()

def create_wood_planks(path):
    dwg = svgwrite.Drawing(path, size=(256, 256))
    dwg.add(dwg.rect(insert=(0, 0), size=('100%', '100%'), fill='#8B5A2B'))
    for i in range(0, 256, 32):
        dwg.add(dwg.line(start=(0, i), end=(256, i), stroke='#734A24', stroke_width=4))
    dwg.save()

TEXTURES = {
    'metal_plate.svg': create_metal_plate,
    'wood_planks.svg': create_wood_planks,
}

if __name__ == '__main__':
    output_dir = os.path.join('assets', 'Data', 'Textures')
    os.makedirs(output_dir, exist_ok=True)
    for filename, func in TEXTURES.items():
        func(os.path.join(output_dir, filename))
