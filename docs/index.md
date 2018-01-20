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




<div class="container marketing">
  <div class="row">
  {% assign item_number = site.project_description | size %}
  {% assign container_size = 12 | divided_by: item_number %}
    {% for item in site.project_description %}
      {% assign section_title = item.title | split: " " %}
      <div class="col-lg-{{ container_size }}">
        <img class="rounded-circle" src="{{ item.head_image | prepend:site.baseurl }}" alt="{{ item.head_image | remove: ".png" | replace: "-", " " | capitalize }}" width="140" height="140">
        <h2> {{ section_title[1] | capitalize }} </h2>
        <p></p>
        <p><a class="btn btn-secondary" href="#{{ item.title }}" role="button">View details &raquo;</a></p>
      </div>
    {% endfor %}
  </div>
</div>

{% for item in site.project_description %}
  {% assign section_title = item.title | split: " " %}
  <div class="blog-post">
    <h2 class="blog-post-title" id="{{ item.title }}">{{ section_title[1] }}</h2>
    {{ item.content }}
  </div>
{% endfor %}
