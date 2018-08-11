
/**
 * User can submit form under 3 minutes
 * after that they will be unable to submit and redirect to home page
*/
var canSubmit = true;

/**
 * Validates birth date
 * @param {string} birth
 * @throws Error
 */
const validateBirth = (birth) => {
  if (!(/^(?:(?:31(\/)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/)(?:0?[1,3-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$/.test(
    birth,
  ))) {
    throw new Error('Invalid date format');
  } else {
    const birthSplit = birth.split('/');
    const birthDate = new Date(birthSplit[2], birthSplit[1]-1, birthSplit[0]);
    const currentDate = new Date();
    const milliDay = 1000 * 60 * 60 * 24;
    const ageInDays = (currentDate - birthDate) / milliDay;
    const ageInYears = Math.floor(ageInDays / 365);
    if (ageInYears < 15 || ageInYears > 80) {
      throw new Error('Applicant must be between 15 and 80 years of age');
    }
  }
};

/**
 * Validates post code against state
 * @param {string} post
 * @param {string} state
 * @throws Error
 */
const validatePostCode = (post, state) => {
  const e = 'Invalid post code';
  switch (state) {
    case 'VIC':
      if (post.indexOf('3') !== 0 && post.indexOf('8') !== 0) {
        throw new Error(e);
      }
      break;
    case 'NSW':
      if (post.indexOf('1') !== 0 && post.indexOf('2') !== 0) {
        throw new Error(e);
      }
      break;
    case 'QLD':
      if (post.indexOf('4') !== 0 && post.indexOf('9') !== 0) {
        throw new Error(e);
      }
      break;
    case 'NT':
      if (post.indexOf('0') !== 0) {
        throw new Error(e);
      }
      break;
    case 'WA':
      if (post.indexOf('6') !== 0) {
        throw new Error(e);
      }
      break;
    case 'SA':
      if (post.indexOf('5') !== 0) {
        throw new Error(e);
      }
      break;
    case 'TAS':
      if (post.indexOf('7') !== 0) {
        throw new Error(e);
      }
      break;
    case 'ACT':
      if (post.indexOf('0') !== 0) {
        throw new Error(e);
      }
      break;
    default:
      throw new Error(e);
  }
};

/**
 * Returns element by id
 * @param {string} id 
 */
const elmById = (id) => document.getElementById(id);

/**
 * Validates if other skills is set
 * @throws Error
*/
const validateOtherSkills = () => {
  if (elmById('other').checked === true) {
    if (elmById('other-skills').value === '') {
      throw new Error('Other skills text cannot be empty');
    }
  }
};

/**
 * Handles form submit by validating fields
 * @returns boolean
 */
const handleSubmit = () => {
  try {
    if (canSubmit) {
      validateBirth(elmById('date-of-bith').value);
      const state = sessionStorage.getItem('state');
      validatePostCode(elmById('postcode').value, state || '');
      validateOtherSkills();
      return true;
    } else {
      throw new Error('Cant submit form after 3 minutes');
    }
  } catch (e) {
    Toastify({
      text: e,
      duration: 5000,
      close: true,
      gravity: 'top',
      positionLeft: false,
      backgroundColor: 'linear-gradient(to right, #ff00cc, #333399)',
    }).showToast();
    if (!canSubmit) {
      window.location.pathname = '/';
    }
    return false;
  }
}

const addListener = () => {
  [
    'first-name',
    'last-name',
    'date-of-bith',
    'street-address',
    'suburb-town',
    'postcode',
    'email-address',
    'phone-number',
    'other-skills',
  ].forEach(element => {
    elmById(element).addEventListener('keyup', (event) => {
      sessionStorage.setItem(element, event.target.value);
    });
  });
  elmById('state').addEventListener('change', () => {
    sessionStorage.setItem('state', event.target.value);
  });
  ['gender-m', 'gender-f'].forEach(element => {
    elmById(element).addEventListener('click', (event) => {
      sessionStorage.setItem('gender', event.target.id);
    });
  });
  ['verbal-skill', 'computer-skill', 'energy-skill', 'standards-skill', 'other'].forEach(element => {
    elmById(element).addEventListener('click', (event) => {
      sessionStorage.setItem(element, event.target.checked);
    });
  });
};

const loadFields = () => {
  [
    'job-reference-number',
    'first-name',
    'last-name',
    'date-of-bith',
    'street-address',
    'suburb-town',
    'postcode',
    'state',
    'email-address',
    'phone-number',
    'other-skills',
  ].forEach(element => {
    let value = sessionStorage.getItem(element);
    if (value !== null) {
      elmById(element).value = value;
    }
  });
  let gender = sessionStorage.getItem('gender');
  if (gender !== null) {
    elmById(gender).checked = true;
  }
  ['verbal-skill', 'computer-skill', 'energy-skill', 'standards-skill', 'other'].forEach(element => {
    let value = sessionStorage.getItem(element);
    if (value !== null) {
      elmById(element).checked = value;
    }
  });
};

const startTimer = () => {
  Toastify({
    text: 'You have only 3 minutes to submit the form',
    duration: 5000,
    close: true,
    gravity: 'top',
    positionLeft: false,
    backgroundColor: 'linear-gradient(to right, #ff00cc, #333399)',
  }).showToast();
  let time = 3;
  setInterval(() => {
    time -= 1;
    Toastify({
      text: 'You have only '+time+' minutes to submit the form',
      duration: 5000,
      close: true,
      gravity: 'top',
      positionLeft: false,
      backgroundColor: 'linear-gradient(to right, #ff00cc, #333399)',
    }).showToast();
    if (time === 0) {
      canSubmit = false;
    }
  }, 60000);
};

window.onload = () => {
  elmById('apply-form').onsubmit = handleSubmit;
  loadFields();
  addListener();
  startTimer();
};
