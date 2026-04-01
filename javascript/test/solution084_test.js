var assert = require('assert');
var solution084 = require('../src/euler/solution084');

describe('Solution084', function() {
  describe('answer', function() {
    it('will answer problem 084', function() {
      assert.equal(solution084.answer(), '101524');
    });
  });
});