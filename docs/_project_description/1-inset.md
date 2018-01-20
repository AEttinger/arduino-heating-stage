---
layout: desc
head_image: '/assets/images/cad-stage-inset.png'
---
<figure class="figure float-left" style="max-width:400px">
  <img class="figure-img img-fluid rounded" style="max-width:400px" alt="CAD of the stage inset" src="{{'/assets/images/cad-stage-inset.png' | prepend: site.baseurl }}">
  <figcaption class="figure-caption">CAD of the stage inset</figcaption>
</figure>
For specific microinjection experiments, we needed a heating stage that would be compatible with our Leica microinjection microscope and hold large cover glasses. Commercial solutions were either expensive or not quite what we wanted so I decided to build a custom stage heating inset with an Arduino.

From a different project I knew that Peltier elements can be used for efficiently heating a stage (even though now I'd probably consider ceramic heating elements or heating strips if there is no cooling needed). Together with our workshop, we designed a stage inset that would fit the standard Leica stage holder, and have cut-outs for two Peltier elements.

Just a small note, if anybody wants to use this design: In the CAD files I used dimensions fitting the round stage *exactly*, so in the end we needed to trim a few millimeters away of the inset so it did not get stuck in the stage.

<figure class="figure float-right" style="max-width:400px">
  <img class="figure-img img-fluid rounded" alt="Stage inset" src="{{'/assets/images/stage-inset-assembled-nocover.jpg' | prepend: site.baseurl }}">
  <figcaption class="figure-caption">The final piece cut from aluminium. Covers are removed to reveal cut-out for the peltier elements.</figcaption>
</figure>

As a next step, I glued in the Peltier elements with electrically non-conductive, but heat-conducting epoxy glue. This stuff had tons of warning labels, so I did this under the fume hood. I also added one Thermistor next to the Peltiers to later establish a feedback loop for temperature control.

<figure class="figure float-left" style="max-width:400px">
  <img class="figure-img img-fluid rounded" alt="Stage inset with Peltiers and Thermistors" src="{{'/assets/images/stage-inset-show-peltiers-thermistors.jpg' | prepend: site.baseurl }}">
    <img class="figure-img img-fluid rounded" alt="Stage inset" src="{{'/assets/images/stage-inset-thermistor-and-peltier-glued.jpg' | prepend: site.baseurl }}">
  <figcaption class="figure-caption">Inset with Peltier elements and thermistors before and after gluing.</figcaption>
</figure>
