# RinaChanBoard
 Code, STLs and info to crate a working Rina-Chan Board from Love Live!

## Required Hardware 
* Seeduino Xiao - This is the smallest arduino-compatible board I've found. https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html
* 4x 8x8 WS2812B RGB LED boards - these will overlap but gives you a 14x13 LED area. It's enough to get good looking expressions for both eyes and face. You can also use 120 LED/m strips and manually lay them out and solder them. This will likely produce a better result, but the STL grid is not designed for that so you'll have to modify the blank plate yourself. https://www.aliexpress.com/item/32671025605.html?spm=a2g0o.productlist.0.0.11262003pT4QEB&algo_pvid=b686eb48-1610-4766-9f20-6cd590368dc6&algo_expid=b686eb48-1610-4766-9f20-6cd590368dc6-0&btsid=0bb0623a16070721634436854e578d&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_
* 3x push buttons. One each for selecting mouth and eyes, and one for confirming your selection. I didn't have any in so I bought this, which comes with button caps too. They are a little big so you might prefer smaller ones. https://www.amazon.co.uk/gp/product/B07Q22YP41/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
* 3x 10k resistors - to tie the ground pin of the buttons.
* Wires, solder, etc
* OPTIONAL: Seeeduino Grove battery board. This is technically optional but I *highly* recommend it as it has a built in battery management board, with very little increase in used space. https://wiki.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-embedded-battery-management-chip/
* OPTIONAL: LiPo battery. Doesn't need to be very big, I used this. https://www.amazon.co.uk/gp/product/B08215N9R8/ref=ppx_yo_dt_b_asin_image_o08_s01?ie=UTF8&psc=1
* OPTIONAL: JST connectors or Molex connectors for the battery. So you can easily disconnect it if needed. The above battery comes with a molex, I bought these JST connectors so had to solder the new connector on to it anyway because I'm an idiot and can't read. https://www.amazon.co.uk/gp/product/B07449V33P/ref=ppx_yo_dt_b_asin_image_o08_s00?ie=UTF8&psc=1

If you're not going to use the grove battery board you can roll your own solution but I found this was the easiest solution with very few drawbacks.
