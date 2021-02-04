let countDown;
const timerDisplay = document.querySelector('.display__time-left');
const endTime = document.querySelector('.display__end-time');

const buttons = document.querySelectorAll('[data-time]');

function timer(seconds){
  clearInterval(countDown);
  /*
  Tabbing out from the window for a long time sometimes pauses the timer +
  iOS disables timers when scrolling for performance issues

  setInterval(function() {
    seconds--;
  }, 1000);
   */

  const now = Date.now();
  const then = now + seconds * 1000;
  displayTimeLeft(seconds);
  displayEndTime(then);

  countDown = setInterval(() => {
    const secondsLeft = Math.round((then - Date.now()) / 1000);
    if(secondsLeft < 0) {
      clearInterval(countDown);
      return;
    }

    displayTimeLeft(secondsLeft);
  }, 1000);
}

function displayTimeLeft(seconds) {
  const minutes = Math.floor(seconds / 60);
  const remainderSeconds = seconds % 60;
  const display = `${minutes}:${remainderSeconds < 10 ? '0' : ''}${remainderSeconds}`;

  document.title = display;

  timerDisplay.textContent = display;
}

function displayEndTime(timestamp){
  const end = new Date(timestamp);
  const hours = end.getHours();
  const minutes = end.getMinutes();
  endTime.textContent = `Be back @ ${hours}:${minutes < 10 ? '0' : ''}${minutes}`;
}

function startTimer(){
  const seconds = parseInt(this.dataset.time);
  timer(seconds);
}

buttons.forEach(button => button.addEventListener('click', startTimer));
document.customForm.addEventListener('submit', function(e) {
  e.preventDefault();
  const mins = this.minutes.value;
  timer(mins * 60);
  this.reset();
});
