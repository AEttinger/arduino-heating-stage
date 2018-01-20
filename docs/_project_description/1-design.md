---
layout: desc
head_image: '/assets/images/cad-stage-inset.png'
---

For specific microinjection experiments, we needed a heating stage that would be compatible with our Leica microinjection microscope and hold large cover glasses. After looking into commercial solutions that were either expensive, or not quite what we wanted, and since I anyway wanted to learn more about microcontrollers, I decided to build a custom stage heating inset with an Arduino.

From a different project I knew that Peltier elements can be used for efficiently heating a stage (even though now I'd probably consider ceramic heating elements or heating strips if there is no cooling needed). Together with our workshop, we designed a stage inset that would fit the standard Leica stage holder, and have cut-outs for two Peltier elements. <img class="float-left" alt="CAD of the stage inset" src="{{'/assets/images/cad-stage-inset.png' | prepend: site.baseurl }}">

Just a small note, if anybody wants to use this design: In the CAD files I used dimensions fitting the round stage *exactly*, so in the end we needed to trim a few millimeters away of the inset so it did not get stuck in the stage.

Here the final piece cut from aluminium: <img class="rounded float-right img-fluid" style="max-width:400px" alt="Stage inset" src="{{'/assets/images/stage-inset-assembled-nocover.jpg' | prepend: site.baseurl }}">
