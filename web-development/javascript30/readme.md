![](https://javascript30.com/images/JS3-social-share.png)

# JavaScript30 Challenge

I'm starting the #100DaysOfCode with the [JavaScript30](https://JavaScript30.com).
Goal is to do 1 challenge / day, but I hope I can sometimes squeeze in a second challenge.

Grab the course at [https://JavaScript30.com](https://JavaScript30.com)
Text-based guides (unofficial) for the challenges can be found here - [Text Guides](https://github.com/nitishdayal/JavaScript30).

Thank you [wesbos](https://github.com/wesbos), so far these have been great!


# Daily Tracker
## Day 1: Drum Kit
Good way to start out with #100DaysOfCode. Learned about keyEvents, playing audio, transitionEvents and how talk to the document without jQuery.

## Day 2: Clock
I had troubles with removing the stutter from the Clock. I tried solving it by setting the transition property on the element, but that didn't work out.
`secondHand.style.transition = (seconds === 0) ? 'none' : 'all 0.5s';`

I tried adding / removing a css-class which sets the transition temporarely to none.
`(seconds === 0) ? secondHand.classList.add('notransition') : secondHand.classList.remove('notransition');`

I'm still puzzled why the first attempt did not work. Any ideas?

## Day 3: CSS Variables
I didn't even know these existed, mind blown.
You can set css dynamically by using setProperty, it accepts a name and a value.
```javascript
document.documentElement.style.setProperty(`--${this.name}`, this.value + suffix);
```

Another thing to note here, that CSS variables break, when using it like ```color: var(--base);``` in stead of `color: var (--base);`

## Day 4: Array Cardio 1 - 4
The first couple exercises were pretty straightforward. `console.table()` is a superb way to display arrays of objects, first time I've used it!

You can convert nodelist to arrays, via `Array.from(nodeList)` or `[...nodeList]`, since the nodeList only supports forEach. The array spread operator takes every item out of a multiple element something.

Destructering assignment makes it possible to get data from an array or object and put them in variables.
```javascript
//example from mdn: https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment
[a, b, ...rest] = [1, 2, 3, 4, 5];
console.log(a); // 1
console.log(b); // 2
console.log(rest); // [3, 4, 5]
```

Reduce takes function as the first argument and an optional starting value, this can be anything.
The first argument of the function takes a value, which has to be same type as the starting value. The second argument however is an element from the array.
The function should also return the same type as the starting value / first argument.

```javascript
const transportation = data.reduce(function(obj, item) {
            if (!obj[item]) obj[item] = 0;
            obj[item]++;
            return obj;
        }, {});
```

## Day 5: Flex Panels Image Gallery
On several occasions I've come across, I usually got frustrated. Mostly, because of a lack of knowledge.

### What did I learn?
Each flex container should have a `display: flex`, it does not inherit from previous container. `flex: 1` evenly distributes the extra space of a container over all children.
If an element in a container has `flex: 5`, while the others are `flex: 1`, that element will take up 5 times the amount of space.
`align-items: center` centers the items on x-axis, while `space-between: center` centers them on the y-axis.

`transition` and `transform` are powerful tools, I should try to work with more often + they look make it look cool. `transform` was used to move top and bottom text out of the current screen, until an item has been clicked, which `transtion` the text back in.

## Day 6: Ajax Type Ahead
The goal was to make an auto complete search input of states and cities, while also displaying the population of the state. Beautiful product!

### What did I learn?
`fetch()` is new method of getting data from an external source and uses promises instead of callbacks to notify when the data arrived.
```javascript
//callback
fetch(endpoint, function(data){
console.log(data);
});
//promise
fetch(endpoint).then(data){
console.log(data);
}
```
The data which comes back from fetch is raw data and it's converted to json, by using `data.json()`.

Array spread operator can be used with `Array.push()`, it will take each element from the data and passes it as multiple individual arguments into push, thus not creating a nested array.

The power of `Array.map()`, used to map over all filtered results and converting them into HTML-elements, by using template strings and literals.
`element.innerHTML` can only deal with strings, therefore make sure to `Array.join()` the individual li-elements.

It's not possible to use variables inside `String.match()`.
```javascript
const regex = new RegExp(wordToMatch, 'gi');
const word.match(regex);
```

## Day 7: Array cardio Day 2
Today's challenge was an extension of Day 4, this time I came up with all solutions beforehand.

### What did I learn?
Removing items from an array could be done with mutating the array, or not.

```javascript
/* Removes the element from the original array, thus mutating the array */
array.splice(index, 1);

/* Creates a new array without the removed item, thus not mutating the array.
Immutable data is popular with Redux and functional programming in general. */
const newArray = [
...array.slice(0, index),
...array.slice(index + 1)
]
```

## Day 8: Fun with HTML5 Canvas
It was nice to do something creative, the bright colours and the canvas were exciting.

### What did I learn?
Everything about canvas was new to me, since I never knew of it's existense. Super fun exercise, because of all the new syntax, but also a bit harder to let it all sink in properly. I''ll have fiddle with the canvas some more.

Grab the context of the canvas.
```javascript
const canvas = document.querySelector('#draw');
const ctx = canvas.getContext('2d');
```
Adjusting the context can be done by multiple properties.
```javascript
ctx.strokeStyle = '#BADA55';
ctx.lineJoin = 'round';
ctx.lineCap = 'round';
ctx.lineWidth = 50;
ctx.globalCompositeOperation = 'multiply';
```
Add multiple event listeners and the canvas, to check for mouseup, -down, -move and -out.
```javascript
canvas.addEventListener('mousemove', draw);
canvas.addEventListener('mousedown', (e) => {
    /* Update lastX and lastY set the offset */
    isDrawing = true;
    [lastX, lastY] = [e.offsetX, e.offsetY];
});
canvas.addEventListener('mouseup', () => isDrawing = false);
canvas.addEventListener('mouseout', () => isDrawing = false);
```
Finally it's time to draw the line.
```javascript
    ctx.strokeStyle = `hsl(${hue}, 100%, 50%)`;
    ctx.beginPath();
    /* Start from */
    ctx.moveTo(lastX, lastY);
    /* Go to */
    ctx.lineTo(e.offsetX, e.offsetY);
    ctx.stroke();
    lastX = e.offsetX;
    lastY = e.offsetY;
```

Destructering is a nice way of setting multiple variables to a certain value in one line.
```javascript
[lastX, lastY] = [e.offsetX, e.offsetY];
```

## Day 9: 14 Must knows console tricks
### What did I learn?

The most useful console methods at first glance would be
```javascript
console.log('Hello');
console.table([{}, {}]);
console.warn('Warning');
console.error('Error');
console.info('Info');

console.dir(element); //Gives the object of the element
console.time('t1');
console.timeEnd('t1'); //string has to be the same
```

## Day 10: Hold Shift to Check Multiple Checkboxes
Resting after feeing sick/miserable restored me again to do the next day in the Javascript30.
Not to mention I did mmy first PR in open source today, I love [eslint]()

### What did I learn?

Besides triggering on mouseclick the 'click' event also triggers on keyboard presses.
A reminder that nodeLists can only use `forEach`.

## Day 11: Custom HTML5 Video Player
Yesterday's challenge was a bit boring, but wow, did I enjoy this one.
I thought we would need a lot more code to control the the buttons of the custom HTML5 video player.

Wesbos is fantastic in breaking down big problems into small chunks, which makes solving the problem easier.

### What did I learn?
Small chunks solve problems. In the end it boils down to 1) finding the elements 2) adding event listeners 3) and hooking the event listeners to functions.

I'm starting to feel more and more comfortable using `addEventListener` and `document.querySelector`.

A `timeupdate` event listener is fired whenever the time gets updated. It perfectly handles the progressBar of the video using `style.flexBasis`.

The mousedown boolean is used as flag to trigger the calculation where the video is based on the position of the progressBar.
Notice `(e) => mousedown && scrub(e)`, which returns early (not calling `scrub(e)`) when the mouse isn't pressed down.
```javascript
let mousedown = false;
progress.addEventListener('click', scrub);
progress.addEventListener('mousemove', (e) => mousedown && scrub(e));
progress.addEventListener('mousedown', () => mousedown = true);
progress.addEventListener('mouseup', () => mousedown = false);
```

## Day 12: Key Sequence Detection
### What did I learn?

When using `Array.slice(index, numberOfElements)`, you set the index to a negative number and the numberOfElements is greater than the remaining elements, it will continue with index 0, then index 1. And so on.

Cornify your page like a pro:
```javascript
<script type="text/javascript" src="http://www.cornify.com/js/cornify.js"></script>
```

## Day 13: Slide in a Scroll
My PR for eslint got merged. WOOOOOOO!

### What did I learn?
I have a lot to learn! I picked up Eloquent Javascript again and hopefully I can finish it around the same time as Javascript30. That way I'm fully prepared to dive into the frontend projects on FreeCodeCamp with plain Javascript! :)

If conditionals are getting to hard to understand, wrap them into a variable so it's easier to understand, once you come back to the code.

The `window` has a ton of properties I'm unfamiliar with.

## Day 14: Object and Arrays - Reference vs Copy
Amazing challenge! Hopefully from now one references and copies won't bite me as much as they used to!

### What did I learn

The values of `strings`, `numbers` and `booleans` go into a variable. Updating the variable does not update the value of other variables.

Assigning an array to an original array actually just points to the reference of the original array. Editing the array, also changes the original array.
```javascript
const players = ['Hans Gruber', 'Kevin', 'Mari'];
const team = players;
team[0] = 'Not Hans';
// players = ['Not Hans', 'Kevin', 'Mari']
// team = ['Not Hans', 'Kevin', 'Mari']
```
There are a couple way to make an actual copy of the original array:
```javascript
const players = ['Hans Gruber', 'Kevin', 'Mari'];
const team = [...players]; // Spread operator takes all elements from original array
const team1 = Array.from(players); // Creates an array from an array
const team2 = players.slice(); // Slicing without slicing out anything makes a copy of the array
const team3 = [].concat(players); // Concatenating an empty array with an array
```

Objects have the same problems as arrays. Changing properties on the reference changes the properties of the original object. Creating an actual copy of the original object can be done in a couple ways.

```javascript
const me = {
  name: 'Kevin R',
  age: 25
};
const captain = Object.assign({}, person, { number: 99 }); // Blank object, the rest folds in and overwrite the new properties, without mutating the original object
const cap2 = {...me}; // ESNext Spread Operator (coming hopefully)
```

Creating a copy of an object with `Object.assign()` only copies one level deep. In order to fully clone an object you'll need something like `_.cloneDeep()` from `lodash`. The poor man's deep clone: `const clone = JSON.parse(JSON.stringify(object))`
Deep cloning is rarely used, because of performance issues.

## Day 15: LocalStorage and Event Delegation
Yay, halfway through the Challenge!

### What did I learn?
Submitting a form, refreshes the page unless `e.preventDDefault()` is called inside the function.

Shorthhand for creating objects:
```javascript
const text = "I'm a parrot. Arrr!";
const parrot = { text: text, name: "Roger" };
// can be written like
const parrot = { text, name: "Roger" };
```

Local storage only works as key-value pairs, where the value can only be a string. When it sees something it doesn't understand the local storage tries to `toString()` it.
Data should be stored in the local storage by calling `JSON.stringify()` before storing it. When retrieving data from local storage, you shoulld convert if back to an object using `JSON.parse()`.
```javascript
// saving
localStorage.setItem('key', JSON.stringify(value));

// retrieving
JSON.parse(localStorage.getItem('key'));
```

Event delegation is useful in a sense that when an event listener is added to the parent, the parent can pass down the event to the child where the event was triggered on.
The event listeners of children are removed when adding / removing child elements, there it's better that the parent *delegates* the events of it's children.
```javascript
const el = document.querySelecter('element');

function logMe(e){
  if(!e.target.matches('element')) return; // returns early
  console.log(e.target);
}

// notice how the event is added to the parent of 'element'
// if a second 'element' is created, the parent will delegate properly
parent.addEventListener('click', logMe);
```

## Day 16: CSS Text Shadow Mouse Move Effect
### What did I learn?

HTML tag are layered on top of each other. Event listeners which were added to a parent element are
also triggered on it's child elements. I assume this is also what event delegation does?
```javascript
function executeMe(e){
  // this does not always equal to e.target
  // this references to the object where the event is listening on (hero)
  // e.target can be triggered by any child elements of el
}

el.addEventListener('mousemove', executeMe)
```

## Day 17: Sorting band names withou articles
### What did I learn

The `innerHTML` of element uses `toString()` when it isn't set to one. Don't forget to clean the code
when chaining methods in Javascript. Nobody likes long lines of code.
```javascript
const bandsEl = document.querySelector('#bands').innerHTML =
            sortedBands
            .map(band => `<li>${band}</li>`)
            .join('');
```

## Day 18: Tally Strings Times with Reduce
### What did I learn?

Convert nodeLists using `Array.from(nodeList)` or `[...nodeList]`.

## Day 21: Geolocation based Speedometer and Compass
### What did I learn?

Accesing the geolocation by using `navigator.geolocation.watchPosition()`. There are other methods, but watchPosition gives you frequent data updates.

The geolocation API contains a heading (offset in degrees from North), speed, x- and y coords...

## Day 19 Webcam Fun
Wow, this was a blast. I didn't think we could do so much with Javascript and CSS to get all the webcam effects. Pretty neat!

### What did I learn?

The effects were super nice, but one thing I want to remember is how files can be downloaded in the browser.
```javascript
function takePhoto() {
    const data = canvas.toDataURL('image/jpeg');
    // create the link
    const link = document.createElement('a');
    link.href = data;
    link.setAttribute('download', 'handsome');
    link.innerHTML = `<img src="${data}" alt="Handsome Person" />`;
    strip.insertBefore(link, strip.firstChild);
}
```

Getting the video from the device can only be done by a secure origin, because it's accesing stuff outside the browser I think?
Capturing the webcam stream is surprisingly easy! I really should look into navigator, seems like a lot of awesome stuff
can be done there.
```javascript
function getVideo() {
    navigator.mediaDevices.getUserMedia({
            video: true,
            audio: false
        })
        .then(localMediaStream => {
            // the video element
            video.src = window.URL.createObjectURL(localMediaStream);
            video.play();
        })
        .catch(error => console.log(error, "No webcam allowed"));
}
getVideo();
```

In order to modify the webcam stream we have to capture all the pixels of the webcam stream, pass it
through a modifier, which modifies the RGB values of each pixel. After modifying the pixels the image is
painted on the canvas.
```javascript
function paintToCanvas() {
    const width = video.videoWidth;
    const height = video.videoHeight;
    canvas.height = height;
    canvas.width = width;

    return setInterval(() => {
        ctx.drawImage(video, 0, 0, width, height);
        let pixels = ctx.getImageData(0, 0, width, height);
        ctx.globalAlpha = 0.1; //gives a spooky effect
        pixels = greenScreen(pixels);
        ctx.putImageData(pixels, 0, 0);
    }, 16);
}
```

The pixels can be modified, pixel per pixel. We can't use regular array methods on the `pixels.data` array, because
it's a special kind of array. Array[0] = R, array[1] = G, array[2] = B and array[3] = alpha.
```javascript
function rgbSplit(pixels) {
    for (let i = 0; i < pixels.data.length; i += 4) {
        pixels.data[i - 150] = pixels.data[i + 0];
        pixels.data[i + 500] = pixels.data[i + 1];
        pixels.data[i - 500] = pixels.data[i + 2];
    }
    return pixels;
}
```

## Day 20: Speech Recognition
### What did I learn?

The speech recognition is not suited for my English, it could barely understand what I was trying to see. I can't blame it, though! Setting up the speech recognition was suprisingly easy (just make sure the mic works).

At the time of creating the challenges FireFox already implemented those, while chrome is still using WebKit's implementation. I tried hooking it up on Mozilla FireFox, but it didn't seem to recognise my microphone and it threw an error at `new SpeechRecognition()`.
I installed the Chrome Canary and it worked!

The recognised strings can be found by creating an array of the list `event.results`. The event is hooked up on `recognition` and is listening for `result`.
```javascript
const transcript = Array.from(e.results)
                .map(result => result[0])
                .map(result => result.transcript)
                .join('');
```

I haven't seen this yet, but a lot of Javascript30 Challenges gives inspirations to do silly side-projects. Speech Recognition is definetly an interesting topic to dig deeper into.

## Day 22: Follow Along Links
Notice the navigation bar of [Stripe](https://stripe.com). Highlighting and resizing links will help us tackle a later challenge to replicate the dropdown menu.

### What did I learn
In order to properly highlight the element with the correct rectangle (different words have different measurements) `element.getBoundingClientRect()` is used to calculate to position of hovered element on the page.

```javascript
 function highlightLink() {
            const linkCoords = this.getBoundingClientRect();
            highlight.style.width = `${linkCoords.width}px`;
            highlight.style.height = `${linkCoords.height}px`;
            highlight.style.transform =
                `translate(${linkCoords.left + window.scrollX}px, ${linkCoords.top + window.scrollY}px)`;
        }
```

## Day 23: Speech Synthesis
### What did I learn
FireFox, just like with Speech Recognition didn't seem to work properlly, if even at all. I worked with Chrome Canary for this one.

The `SpeechSynthesisUtterance` contains information about the content and how it should read the content.
The `SpeechSynthesis` is used to control the speech, getting the different language options, ...

Passing an argument to a callback function can be done in two ways.
```javascript
  // bind calls the function, passes the value of this and then an argument
  stopButton.addEventListener('click', toggle.bind(null, false));
  // arrow function (react)
  stopButton.addEventListener('click', () => toggle(false));
```

## Day 24: Sticky Nav
Sticky nav without Bootstrap? X.X :D
### What did I learn?

Setting an element to `position:fixed` will cause the element to take up 0 pixels of space on the page.
The result moves all the content slightly above where it used to be when the element didn't have the fixed height.
The behaviour can be adjust by adding the height of what the element would take up.

Transitions do not work when transitioning from `width: 0` to `width: auto`. Use `max-width` instead.
```css
li.logo {
  max-width:0;
  overflow: hidden;
  background: white;
  transition: all .5s;
  font-weight: 600;
  font-size: 30px;
}

.fixed-nav li.logo {
    max-width: 500px;

}
```

## Day 25: Event Capture, propagation, bubbling and once
### What did I learn?
When clicking on child elements, in fact we also click on it's parent, because of propagation.
The browser will ripple down trying to capture what element was the source of the trigger, then when it found the element the browser bubbles up the event.

tldr: Capturing the location of click (down), then fires events (bubblle up) when the location was found.


```javascript
const divs = document.querySelectorAll('div');

function clickMe(e) {
  e.stopPropagation(); // stops bubbling up - capturing down
}

divs.forEach(div => div.addEventListener('click', logText), {
// options object
capture: false // default: runs the event on bubble up (true runs on capture down)
once: false // default: trigger once, then remove eventListener


})
```

## Day 26: Stripe Follow Along
### What did I learn?

Animating something on/off the screen should be done by toggling `opacity` and `display`. Showing the element should be done by adding `display: block`, then `opacity: 1`. That way the element will be available for targeting, before actually transitioning the opacity.

A lot of rectangle calculations are needed in order to accomplish the behavior. I'm still
not comfortable enough with calculating positions, widths, heights, etc of elements.

```javascript
function handleEnter(){
  this.classList.add('trigger-enter');
  /* short circuiting the addition of trigger-enter-active prevents the content from
  displaying even when the user's mouseovers are too fast */
  setTimeout(() => this.classList.contains('trigger-enter')
   && this.classList.add('trigger-enter-active'), 150);

  background.classList.add('open');

  const dropdown = this.querySelector('.dropdown');
  const dropdownCoords = dropdown.getBoundingClientRect();
  const navCoords = nav.getBoundingClientRect();
  const coords = {
    height: dropdownCoords.height,
    width: dropdownCoords.width,
    // adjust top and left coords when other elements come before or inside the nav
    top: dropdownCoords.top - navCoords.top,
    left: dropdownCoords.left - navCoords.left
  };
}
```

## Day 27: Click and Drag to Scroll
### What did I learn?

I seriously have to start practicing some of the calculation in multiple codePen's, otherwise I feel I won't be doing them at all.
The code is relatively easy, but you have to know which offsets and positions to use in order to effectively calculate.

## Day 28: Video Speed Controller
### What did I learn?
To be honest, not much. Probably one of the less interesting challenges.

## Day 29: Countdown timer
Very interesting challenge as I'm looking to make a pomodoro clock for myself, which I can use at work to be more productive.

### What did I learn?
Using `setInterval()` can lead to unexpected behavior if one isn't cautious enough. Tabbing out of a window for a long time can cause the timer to stop producing values. In iOS timers are disabled when scrolling, because of performance issues.

```javascript
// bad example: If the timer stops, the counting down stops too (single point of failure)
setInterval(function() {
  seconds--;
}, 1000);

// good example: If the timer stop for whatever reason, when it starts again it will recalculate the current time and adjust based on the set time
const now = Date.now();
const then = now + seconds * 1000;

countDown = setInterval(() => {
  const secondsLeft = Math.round((then - Date.now()) / 1000);
  // prevent timer from going below 0
  if(secondsLeft < 0) {
    clearInterval(countDown);
    return;
  }

  displayTimeLeft(secondsLeft);
}, 1000);
 ```

A neat little trick with template strings to show leading zero on numbers lower than 10.
```javascript
const display = `${minutes}:${remainderSeconds < 10 ? '0' : ''}${remainderSeconds}`;
```

Forms can be directly accessed when the form is given a name.
```javascript
document.customForm.addEventListener('submit', () => {});
```

## Day 30: Whack-a-mole
A lot can be accomplished with a little bit of HTML, smart CSS and simple Javascript. Awesome challenge to end the Javascript 30, even though
I found the Countdown Timer Challenge more interesting in the sense it's going to be more practical for me (I want to make my own pomodoro).

### What did I learn?
When `e.isTrusted = true` the event comes from an actual clicked source, while it'd have been set to false if the event was simulated with Javascript.
Probably there are even hacks to circumvent this, but let's not lie awake at night at this moment.

## What's next?
I'm going to head back into Eloquent Javascript and start digging deeper into the evil world of Javascript.
My next challenge is a blogpost which will summarize the concepts I've learned and bundle the resource I want to look into, whenever I have the time.
