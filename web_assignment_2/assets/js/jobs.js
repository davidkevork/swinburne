
/**
 * Returns element by id
 * @param {string} id 
 */
const elmById = (id) => document.getElementById(id);

/**
 * Sets reference number in session storage
 * @param {EventTarget} event
*/
const apply = (event) => {
  const ref = event.target.dataset.ref;
  sessionStorage.setItem('job-reference-number', ref);
  window.location.pathname = (window.location.pathname).replace('jobs', 'apply');
};

window.onload = () => {
  const links = document.getElementsByClassName('apply');
  for (let index = 0; index < links.length; index++) {
    links[index].addEventListener('click', apply);
  }
};
