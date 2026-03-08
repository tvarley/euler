var assert = require('assert');
var solution027 = require('../src/euler/solution027');

describe('Solution027', function() {
  describe('answer', function() {
    it('will answer problem 027', function() {
      assert.equal(solution027.answer(), -59231);
    });
  });
});
