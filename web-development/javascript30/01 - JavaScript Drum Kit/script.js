/** keyEvents, playing audio, listening for transitionEvents
 **/

function playSound(e) {
    //attribute selector: "audio[data-key='']""
    const audio = document.querySelector(`audio[data-key="${e.keyCode}"]`);
    const key = document.querySelector(`.key[data-key="${e.keyCode}"]`);

    if (!audio) return; //stop the function from running

    audio.currentTime = 0; //rewind to start
    audio.play();

    key.classList.add('playing');
}

/** removing the class with setTimeout is ok, but
     overtime the css animation and the timeout will be out off sync **/
function removeTransition(e) {
    if (e.propertyName !== 'transform') return; //skip
    this.classList.remove('playing'); //this equals to whatever got called against it - key
}

const keys = document.querySelectorAll('.key');
// add eventListeners on each key and listen when a transition ends
keys.forEach(key => key.addEventListener('transitionend', removeTransition));
window.addEventListener('keydown', playSound);
