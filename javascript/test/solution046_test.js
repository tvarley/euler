var assert = require('assert');
var solution046 = require('../src/euler/solution046');

describe('Solution046', function() {
  describe('answer', function() {
    it('will answer problem 046', function() {
      assert.equal(solution046.answer(), 5777);
    });
  });
});