
window.onload = () => {
  window.addEventListener('keypress', (event) => {
    let key = document.getElementById(event.key.toLocaleUpperCase());
    if (key !== null) {
      key.style.background = 'linear-gradient(to right, #c33764, #1d2671)';
      setTimeout(() => {
        key.style.background = 'linear-gradient(to right, #ff00cc, #333399)';
      }, 200);
    }
  });
};
