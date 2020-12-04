![Rina-Chan Board, Glowing and Smiling!](/Images/Complete_Face.jpg)

# RinaChanBoard
 Code, STLs and info to crate a working Rina-Chan Board from Love Live!
 
## The Headset Model

The headset model was purchased from [Etsy](https://www.etsy.com/uk/listing/722676367/love-live-pdp-rina-tennoji-headset?transaction_id=2130833114). It's a brilliant model and fitted the exact purpose I needed it for. I highly recommend it.

The only STLs I am including are ones I personally modified to fit the use case (that is, creating a blank board and adding a grid to it). I am also including the diffuser.scad that I used - this is from thingiverse and is freely available. Use OpenSCAD to modify it to produce the size of grid you need, then attach it to the blank_plate.stl to create your grid. blank_grid.stl is the grid for the overlapped LED boards I used attached to the blank plate already.

Both are janky as hell, becasuse I don't know anything about modelling. 

## Required Hardware 
* Seeduino Xiao - This is the smallest arduino-compatible board I've found. https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html
* 4x 8x8 WS2812B RGB LED boards - these will overlap but gives you a 14x13 LED area. It's enough to get good looking expressions for both eyes and face. You can also use 120 LED/m strips and manually lay them out and solder them. This will likely produce a better result, but the STL grid is not designed for that so you'll have to modify the blank plate yourself. https://www.aliexpress.com/item/32671025605.html?spm=a2g0o.productlist.0.0.11262003pT4QEB&algo_pvid=b686eb48-1610-4766-9f20-6cd590368dc6&algo_expid=b686eb48-1610-4766-9f20-6cd590368dc6-0&btsid=0bb0623a16070721634436854e578d&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_
* 3x push buttons. One each for selecting mouth and eyes, and one for confirming your selection. I didn't have any in so I bought this, which comes with button caps too. They are a little big so you might prefer smaller ones. https://www.amazon.co.uk/gp/product/B07Q22YP41/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
* 3x 10k resistors - to tie the ground pin of the buttons.
* Wires, solder, etc
* OPTIONAL: Seeeduino Grove battery board. This is technically optional but I *highly* recommend it as it has a built in battery management board, with very little increase in used space. https://wiki.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-embedded-battery-management-chip/
* OPTIONAL: LiPo battery. Doesn't need to be very big, I used this. https://www.amazon.co.uk/gp/product/B08215N9R8/ref=ppx_yo_dt_b_asin_image_o08_s01?ie=UTF8&psc=1
* OPTIONAL: JST connectors or Molex connectors for the battery. So you can easily disconnect it if needed. The above battery comes with a molex, I bought these JST connectors so had to solder the new connector on to it anyway because I'm an idiot and can't read. https://www.amazon.co.uk/gp/product/B07449V33P/ref=ppx_yo_dt_b_asin_image_o08_s00?ie=UTF8&psc=1

If you're not going to use the grove battery board you can roll your own battery solution but I found this was the easiest solution with very few drawbacks.

## Designing the Expressions

I used a hacked-together google docs sheet that I coloured in manually and copied the numbers out manually into arrays. There's definitely more clever ways of doing this but I hate working with spreadsheets so I was happy to be manual on this. What is useful in this case is I marked with outlines where the overlaps between the panels are. You can find my doc [here](https://docs.google.com/spreadsheets/d/1Beuz8oJ9O0KB6ERlhMPzRE0FvdVzDu4BHBZgB-ASULc/edit?usp=sharing). Use the adjusted spacing sheet - the first sheet is a full 16x16 matrix which has enough room for full model-accurate expressions. If you're going to use dense strips, I recommend a layout like this. Otherwise, use "adjusted spacing", sheet 2 ("Corrected Numbers") was an intermediary after I got the boards to actually layout the panels correctly, before I worked out any overlapping.

## Assembling the Board 

![Full Board](/Images/Full_Board.jpg)
![Front of the Board](/Images/Front_Board.jpg)
![Back of the Board](/Images/Back_Board.jpg)

My board is kind of a mess but the pinout is simple. Pins 3,5 and 6 are the buttons (these are modifiable consts in the code - they were originally 4,5 and 6 but I stripped the metal from the contact next to 4) and pin 7 (again, modifiable) is the output data line for the LED panels. The panels are 3-wire WS2812Bs, PWR/DIN/GRN. The ones I'm using run off 3.3v just fine - if you're using the battery board I recommend this as tying it to the 5v pin shares the power between the Seeeduino and the board, causing dim LEDs.

Each button has one pin to 3.3V and one pin to ground through a 10k resistor (see arduino's [button page](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button) for more info). The output pin from the button is the one opposite the ground pin.

Once the board is assembled, you can mount the battery in the earcup and glue the board to the side of the headset. The thickness of the plate with the boards attached are such that you will need to glue that in place inbetween the two halves of the front board from the model.

## Assembling the Expression Plate

![Front Plate](/Images/Front_Plate.jpg)
![Back Plate](/Images/Back_plate.jpg)

First, tape/glue your boards together in this format:
BOARD 1 | BOARD 4
BOARD 2 | BOARD 3
This means that in terms of LED order, the top left quadrant is first, then bottom left, then bottom right, then top right. Connect the DOUT -> DIN as appropriate along this pattern - the DIN for top left should be where the board connects, and the DOUT from top right should be unpopulated.

Then sandwich the two front plate holder parts either side of the LED plate and hot glue to hold it in place.
