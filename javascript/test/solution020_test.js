var assert = require('assert');
var solution020 = require('../src/euler/solution020');

describe('Solution020', function() {
  describe('answer', function() {
    it('will answer problem 020', function() {
      assert.equal(solution020.answer(), 648);
    });
  });
});