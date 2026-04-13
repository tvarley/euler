var assert = require('assert');
var solution077 = require('../src/euler/solution077');

describe('Solution077', function() {
  describe('answer', function() {
    it('will answer problem 077', function() {
      assert.equal(solution077.answer(), 71);
    });
  });
});