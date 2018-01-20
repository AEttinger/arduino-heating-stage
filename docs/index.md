---
title: "Arduino heating stage"
tag: arduino hardware
layout: page
---

<div class="container marketing">
  <div class="row">
    <div class="col-lg-4">
      <img class="rounded-circle" src="{{ '/assets/images/cad-stage-inset.png' | prepend: site.baseurl }}" alt="CAD of stage inset" width="140" height="140">
      <h2>Task</h2>
      <p></p>
      <p><a class="btn btn-secondary" href="#task" role="button">View details &raquo;</a></p>
    </div><!-- /.col-lg-4 -->
    <div class="col-lg-4">
      <img class="rounded-circle" src="{{ '/assets/images/arduino-and-shield-part.jpg' | prepend: site.baseurl }}" alt="Arduino and shield" width="140" height="140">
      <h2>Wiring</h2>
      <p></p>
      <p><a class="btn btn-secondary" href="#wiring" role="button">View details &raquo;</a></p>
    </div><!-- /.col-lg-4 -->
    <div class="col-lg-4">
      <img class="rounded-circle" src="{{ '/assets/images/box-assembly-detail.jpg' | prepend:site.baseurl }}" alt="Detail controller box" width="140" height="140">
      <h2>Assembly</h2>
      <p></p>
      <p><a class="btn btn-secondary" href="#assembly" role="button">View details &raquo;</a></p>
    </div><!-- /.col-lg-4 -->
  </div><!-- /.row -->

</div><!-- /.container -->

{% for doc in page.category %}
  {{ doc }}
{% endfor %}


<div class="container">
  <div class="row">
    <div class="col-lg-12">

## Task

## Wiring

## Assembly

    </div>
  </div>
</div>
