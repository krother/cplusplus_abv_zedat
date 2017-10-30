# SharkFighter

**by Sebastian Kulich**

A simple 2D game written in C++ with SDL2. Game development was part of the C++ Programming Course (ABV) at Zedat/FU Berlin in the summer term 2017.

## Game Information
In the main game menu you should use the number keys on you keyboard for your selection.
When you are in the "about" section, you can return to the menu with any key (besides esc).

In game: use (a) for movement to the left, (d) for movement to the right and (w) for a movement upwards. You can basically fly
by pressing up multiple times, but "gravity" will pull you down slowly. You can pause the game always by pressing the esc key.
You can fire your weapon using you mouse cursor and clicking (left or right mouse key doesn't matter). Note: the bullets will only
fly to the point you clicked on the window, but not further!

If a fish comes to close to you, it will bite and cause a damage of 25 Points, so 4 bites means gameover. If a fish touches
down on ground, it causes damage (10%). If destruction level reaches 100% or your life reaches 0 the game is gameover.

Have fun playing!
A quick video of the gameplay can be found [here](http://grmlber.de/vid/sharkfighter.mp4).

### Prerequisites / Dependencies

This game uses SDL2. You will also need the corresponding versions of SDL_image, SDL_TTF and SDL_Mixer.
The CMakeFile.txt uses FindPkgConfig.


### Installing

You can easily use the CMakeFile.txt with cmake.

```
git clone https://github.com/grmlber/sharkfighter.git
cd sharkfighter
cmake .
make
./sharkfighter
```
This should do the job just fine.

Alternatively you can run:
```
git clone https://github.com/grmlber/sharkfighter.git
cd sharkfighter
./build.sh
./sharkfighter
```
However, if your SDL files are in another dir than I included, you might have to adjust them yourself. If you have cmake on you system, I would recommend you try the cmake/make way first.


## Contact

Please feel free to contact me on GitHub or send me an email: [input@grmlber.de](mailto:input@grmlber.de)

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) for more information.

## Acknowledgements

* Thanks to our [teacher/instructor](https://github.com/krother)
* Thanks to the people who have created the artwork and soundfiles and fonts used in this software. Attributions can be found in the [CREDIT.txt](CREDIT.txt) file.

