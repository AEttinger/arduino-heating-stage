---
title: "Arduino heating stage"
tag: arduino hardware
layout: page
---

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
        <p><a class="btn btn-secondary" href="#{{ item.title | replace: " ", "-" | downcase }}" role="button">View details &raquo;</a></p>
      </div>
    {% endfor %}
  </div>
</div>

<hr class="featurette-divider">

<div class="container">
  <div class="row">
    <div class="col-sm-8 blog-main">
      {% for item in site.project_description %}
        {% assign section_title = item.title | split: " " %}
        <div class="blog-post">
          <h2 class="blog-post-title" id="{{ item.title | replace: " ", "-" | downcase }}">{{ section_title[1] }}</h2>
          {{ item.content }}
        </div>
      {% endfor %}
    </div>
  </div>
</div>
