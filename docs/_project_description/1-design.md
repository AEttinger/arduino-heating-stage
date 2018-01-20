---
layout: desc
head_image: '/assets/images/cad-stage-inset.png'
---

For specific microinjection experiments, we needed a heating stage that would be compatible with our Leica microinjection microscope and hold large cover glasses. After looking into commercial solution, and since I wanted to learn more about microcontrollers, I decided to build a custom heating inset with an Arduino.

From a different project I knew that Peltier elements can be used for efficiently heating a stage (even though now I'd probably consider ceramic heating elements or heating strips if there is no cooling needed). Together with our workshop, we designed a stage inset that would fit the standard Leica stage holder, and have cut-outs for two Peltier elements.

![CAD of the stage inset]({{'/assets/images/cad-stage-inset.png' | prepend: site.baseurl }})
