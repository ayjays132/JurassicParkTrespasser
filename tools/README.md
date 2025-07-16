# Texture Generation Tools

This directory contains a simple Python script for generating placeholder
SVG textures. The generated textures are basic patterns that can be used
when testing the modern environment renderer or the VR build.

The script requires the `svgwrite` package which can be installed via pip:

```bash
pip install svgwrite --user
```

Run the script from the repository root:

```bash
python tools/generate_textures.py
```

This populates `assets/Data/Textures` with a few example SVG textures.
You can add additional patterns by editing `generate_textures.py`.
